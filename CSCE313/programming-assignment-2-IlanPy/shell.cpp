#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <vector>
#include <string>

#include "Tokenizer.h"

//added
#include <fcntl.h>

// all the basic colours for a shell prompt
#define RED     "\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE	"\033[1;34m"
#define WHITE	"\033[1;37m"
#define NC      "\033[0m"

using namespace std;

void execution(Tokenizer& tknr, int pipefds[], vector<int>& background, bool is_dollar) {
    int status = 0;
    for(long unsigned int i = 0; i < tknr.commands.size(); i++){
        //create pipe
        if(pipe(pipefds)==-1){
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        // fork to create child
        pid_t pid = fork();
        if (pid < 0) {  // error check
            perror("fork");
            exit(2);
        }

        if (pid == 0) {  // if child, exec to run command
            if(tknr.commands.at(i)->hasOutput()){
                int fd = open(tknr.commands.at(i)->out_file.c_str(), O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
                if(fd < 0){
                    perror("open");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO); // redirect output to write of current pipe
                close(pipefds[0]);
            }
            // need to redirect STDOUT if not last command or only command
            else if(i != tknr.commands.size()-1 || is_dollar){
                dup2(pipefds[1], STDOUT_FILENO); // redirect stdout to write of current pipe
                close(pipefds[0]); // we don't need this
            }
            if(tknr.commands.at(i)->hasInput()){
                int fd = open(tknr.commands.at(i)->in_file.c_str(), O_RDONLY);
                if(fd < 0){
                    perror("open");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(pipefds[1]);
            }

            // run single commands with no arguments
            // char* args[] = {(char*) tknr.commands.at(0)->args.at(0).c_str(), nullptr};
            char** args = new char*[tknr.commands.at(i)->args.size()+1];
            for(long unsigned int j = 0; j < tknr.commands.at(i)->args.size(); j++){
                args[j] = (char*)tknr.commands.at(i)->args.at(j).c_str();
            }
            args[tknr.commands.at(i)->args.size()] = nullptr;

            if (execvp(args[0], args) < 0) {  // error check
                perror("execvp");
                delete[] args; //deallocate args
                exit(2);
            }
        }
        else {  // if parent, wait for child to finish
            // redirect stdin of parent process to read end of the pipe
            dup2(pipefds[0], STDIN_FILENO);
            close(pipefds[1]); // we don't need this

            status = 0; // removed declaration here
            if(!tknr.commands.at(i)->isBackground()){
                waitpid(pid, &status, 0);
                if (status > 1) {  // exit if child didn't exec properly
                    exit(status);
                }
            } else{
                background.push_back(pid);
                cout << "[" << pid << "]" << endl; // cout [PID]
            }            
        }
    }
}

int main () {
    string prev_cwd; // save previous cwd
    vector<int> background; // vector of background processes
    int status = 0;
    for (;;) {
        // need date/time, username, and absolute path to current dir
        // cout << YELLOW << "Shell$" << NC << " ";
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        time_t time_now = time(0);
        string s(ctime(&time_now));
        cout << YELLOW << s.substr(4, 16) << getenv("USER") << ":" << cwd << "$" << NC << " ";

        // check for zombies before scanning next input
        string output_done = "";

        //int pipefds[2]; // Array of file descriptor
        int pipestdin = dup(STDIN_FILENO); // duplicate stdin for later

        // get user inputted command
        string input;
        getline(cin, input);

        // DONE
        for(long unsigned int i = 0; i < background.size(); i++){
            pid_t result = waitpid(background.at(i), &status, WNOHANG);
            if(result > 0){ // success
                output_done += "[" + to_string(background.at(i)) + "]+ Done\n";
                background.erase(background.begin() + i);
                i--;
            }
        }
        if(output_done != ""){
            cout << output_done;
        }

        if (input == "exit") {  // print exit message and break out of infinite loop
            cout << RED << "Now exiting shell..." << endl << "Goodbye" << NC << endl;
            break;
        }

        // implement bonus dollar sign
        int start = 0;
        int end = 0;
        string temp = "";
        char buf[256];
        if(input.find("$(") != string::npos && input.find(")", start+1) != string::npos){
            start = input.find("$(");
            end = input.find(")", start + 1);
            temp = input.substr(start+2, end-start-2);
            Tokenizer tknr_dol(temp);
            if(tknr_dol.hasError()) {
                continue;
            }

            int pipefds[2];
            execution(tknr_dol, pipefds, background, true);
            dup2(pipestdin, STDIN_FILENO);
            int sz = read(pipefds[0], buf, sizeof(buf));
            buf[sz - 1] = '\0';
            string output = buf;
            input.replace(start, (end - start) + 1, output);
        }

        // get tokenized commands from user input
        Tokenizer tknr(input);
        if (tknr.hasError()) {  // continue to next prompt if input had an error
            continue;
        }

        // // print out every command token-by-token on individual lines
        // // prints to cerr to avoid influencing autograder
        // for (auto cmd : tknr.commands) {
        //     for (auto str : cmd->args) {
        //         cerr << "|" << str << "| ";
        //     }
        //     if (cmd->hasInput()) {
        //         cerr << "in< " << cmd->in_file << " ";
        //     }
        //     if (cmd->hasOutput()) {
        //         cerr << "out> " << cmd->out_file << " ";
        //     }
        //     cerr << endl;
        // }

        if(tknr.commands.at(0)->args.size() < 1){
            continue;
        } else if(tknr.commands.at(0)->args.at(0) == "cd"){
            // edge case if only cd
            if(tknr.commands.at(0)->args.size() < 2){
                continue;
            }
            // if cd -
            if(tknr.commands.at(0)->args.at(1) == "-"){
                chdir((const char*)prev_cwd.c_str());
                prev_cwd = cwd;
            // else cd *something*
            } else{
                string path = "";
                if(tknr.commands.at(0)->args.at(1).at(0) == '/'){
                    path = tknr.commands.at(0)->args.at(1);
                } else{
                    path = (string)cwd + "/" + tknr.commands.at(0)->args.at(1);
                }
                prev_cwd = cwd;
                chdir((const char*)path.c_str());
            }
        }
        else{
            int pipefds[2];
            execution(tknr, pipefds, background, false);
            dup2(pipestdin, STDIN_FILENO);
        }
    }
}
