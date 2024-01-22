# include <iostream>
# include <string>
# include <stdexcept>
# include "Post.h"

using std::string, std::vector;

Post::Post(unsigned int postId, string userName, string postText) : postId(postId), userName(userName), postText(postText) {
    if (postId == 0 || userName == "" || postText == "") {
        throw std::invalid_argument("post constructor: invalid parameter values");
    }
}

unsigned int Post::getPostId() {
    return postId;
}

string Post::getPostUser() {
    return userName;
}

string Post::getPostText() {
    return postText;
}

vector<string> Post::findTags() {
    // TODO: extracts candidate tags based on occurrences of # in the post
    vector<string> tags;
    string temp;
    int start_index = 0;
    string::size_type hashtag_pos = 0;
    string::size_type space_position = 0;
    //find each tag
    while((hashtag_pos = postText.find('#', start_index)) != string::npos){
        space_position = postText.find(' ', hashtag_pos);
        if(space_position == string::npos){
            space_position = postText.length();
        }
        temp = postText.substr(hashtag_pos, space_position - start_index);
        tags.push_back(temp);
        start_index = space_position + 1;
    }
    //erase unwanted spaces captured in tag, and turn all to lowercase
    for(unsigned int i = 0; i < tags.size(); i++){
        for(char &character : tags.at(i)){
            character = tolower(character);
        }
        if((space_position = tags.at(i).find(' ')) != string::npos){
            tags.at(i).erase(space_position);
        }
    }
    //remove punctuations at the end
    for(unsigned int i = 0; i < tags.size(); i++){
        for(int j = tags.at(i).length()-1; j >= 0; j--){
            if(tags.at(i).at(j) == '!'
                || tags.at(i).at(j) == ','
                || tags.at(i).at(j) == '.'
                || tags.at(i).at(j) == '?'){
                    tags.at(i).erase(j);
            } else{ break; }
        }
    }
    //remove duplicate tags
    string key;
    unsigned int i = 0;
    unsigned int size = 0;
    unsigned int count = 0;
    vector<int> index;
    while(true){
        if(i >= tags.size()){ break; }
        key = tags.at(i);
        size = tags.size();
        for(unsigned int j = i+1; j < size; j++){
            count++;
            if(key == tags.at(j)){
                index.push_back(j);
            }
        }
        //if ran out of space to search for duplicates, end
        if(count == 0){break;}
        //erase each duplicate, if found.
        for(int j = index.size()-1; j >= 0; j--){
            tags.erase(tags.begin() + index.at(j));
        }
        count = 0;
        i++;
        index.clear();
    }
    return tags;
}
