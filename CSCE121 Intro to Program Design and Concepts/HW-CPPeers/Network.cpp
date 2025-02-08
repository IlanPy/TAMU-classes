# include <iostream>
# include <fstream>
# include <sstream>
# include <stdexcept>
# include "Network.h"

using std::string, std::vector;

Network::Network() : users({}), posts({}), tags({}) {}

void Network::loadFromFile(string fileName) {
    // TODO: load user and post information from file
    std::ifstream inFS;
    string word;
    string line;
    unsigned int postId; string userName; string postText;
    inFS.open(fileName);
    //verify that the file is open
    if(!inFS.is_open()){
        throw std::invalid_argument("");
    }
    while(std::getline(inFS, line)){
        std::stringstream inSTR(line);
        inSTR >> word;
        if(inSTR.fail()){
            throw std::runtime_error("");
        }
        if(word == "User"){
            inSTR >> word;
            if(inSTR.fail()){
                throw std::runtime_error("");
            }
            try{
                addUser(word);
            } catch(...) {throw std::runtime_error("");}
        } else if(word == "Post"){
            inSTR >> postId >> userName;
            std::getline(inSTR, postText);
            if(inSTR.fail()){
                throw std::runtime_error("");
            }
            try{
                postText.erase(0, 1);
                addPost(postId, userName, postText);
            } catch(...) {throw std::runtime_error("");}
        
        } else{
            throw std::runtime_error("");
        }
    }

}

void Network::addUser(string userName) {
    // TODO: create user and add it to network
    for(char &character : userName){
        character = tolower(character);
    }
    for(unsigned int i = 0; i < users.size(); i++){
        if(userName == users.at(i)->getUserName()){
            throw std::invalid_argument("");
        }
    }
    User* newUser = new User(userName);
    users.push_back(newUser);
    //success?
    std::cout << "Added User " << userName << std::endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
    // TODO: create post and add it to network
    //verify that id does NOT exist
    for(unsigned int i = 0; i < posts.size(); i++){
        if(postId == posts.at(i)->getPostId()){
            throw std::invalid_argument("");
        }
    }
    //verify that there is a user with this name
    unsigned int count = 0;
    unsigned int index = 0;
    for(unsigned int i = 0; i < users.size(); i++){
        if(userName == users.at(i)->getUserName()){
            index = i;
            count++;
            break;
        }
    }
    if(count == 0){
        throw std::invalid_argument("");
    }
    //add post to network
    std::vector<std::string> usedTags;
    //1 - create the post
    Post* newPost = new Post(postId, userName, postText);
    //2 - add post to network
    posts.push_back(newPost);
    //3 - add post info to user
    users.at(index)->addUserPost(newPost);
    //4 - extract hashtags
    usedTags = newPost->findTags();
    //5 - search or create tags
    for(unsigned int i = 0; i < usedTags.size(); i++){
        index = 0;
        count = 0;
        for(unsigned int j = 0; j < tags.size(); j++){
            if(usedTags.at(i) == tags.at(j)->getTagName()){
                index = j;
                count++;
            }
        }
        if(count == 0){
            try{
                Tag* newTag = new Tag(usedTags.at(i));
                tags.push_back(newTag);
            } catch(...){}
        }
    }
    //6 - addition of post info to each tag
    for(unsigned int i = 0; i < usedTags.size(); i++){
        for(unsigned int j = 0; j < tags.size(); j++){
            if(usedTags.at(i) == tags.at(j)->getTagName()){
                tags.at(j)->addTagPost(newPost);
            }
        }
    }
    //success?
    std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
    // TODO: return posts created by the given user
    if(userName == ""){
        throw std::invalid_argument("");
    }
    int count = 0;
    int index = 0;
    for(unsigned int i = 0; i < users.size(); i++){
        if(users.at(i)->getUserName() == userName){
            index = i;
            count++;
            break;
        }
    }
    if(count == 0){
        throw std::invalid_argument("");
    }
    std::vector<Post*> allPosts;
    allPosts = users.at(index)->getUserPosts();
    return allPosts;
}

vector<Post*> Network::getPostsWithTag(string tagName) {
    // TODO: return posts containing the given tag
    if(tagName == ""){
        throw std::invalid_argument("");
    }
    int count = 0;
    int index = 0;
    for(unsigned int i = 0; i < tags.size(); i++){
        if(tags.at(i)->getTagName() == tagName){
            index = i;
            count++;
            break;
        }
    }
    if(count == 0){
        throw std::invalid_argument("");
    }
    std::vector<Post*> allTags;
    allTags = tags.at(index)->getTagPosts();
    return allTags;
}

vector<string> Network::getMostPopularHashtag() {
    // TODO: return the tag occurring in most posts
    bool already_there = false;
    vector<string> allTags;
    vector<int> countTags;
    vector<string> maxTags;
    vector<string> someTags;
    int index = 0;
    for(unsigned int i = 0; i < posts.size(); i++){
        someTags = posts.at(i)->findTags();
        for(unsigned int j = 0; j < someTags.size(); j++){
            already_there = false;
            index = 0;
            for(unsigned int k = 0; k < allTags.size(); k++){
                if(someTags.at(j) == allTags.at(k)){
                    already_there = true;
                    index = k;
                    break;
                }
            }
            if(!already_there){
                allTags.push_back(someTags.at(j));
                countTags.push_back(1);
            } else{
                countTags.at(index) = countTags.at(index) + 1;
            }
        }
    }
    int max_index = 0;
    for(unsigned int i = 0; i < countTags.size(); i++){
        if(countTags.at(max_index) < countTags.at(i)){
            max_index = i;
        }
    }
    for(unsigned int i = 0; i < countTags.size(); i++){
        if(countTags.at(max_index) == countTags.at(i)){
            maxTags.push_back(allTags.at(i));
        }
    }
    return maxTags;
}

Network::~Network() {
    for (unsigned int i = 0; i < users.size(); ++i) {
        delete users.at(i);
    }

    for (unsigned int i = 0; i < tags.size(); ++i) {
        delete tags.at(i);
    }
    
    for (unsigned int i = 0; i < posts.size(); ++i) {
        delete posts.at(i);
    }
}
