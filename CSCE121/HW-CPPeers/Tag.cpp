# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector;

Tag::Tag(string tagName) /* TODO: initialize */: tagName(tagName), tagPosts() {
    // TODO: implement constructor checks
    if(tagName.length() < 2
        || tagName.at(0) != '#'
        || !(tagName.at(1) >= 'a' && tagName.at(1) <= 'z')
        || tagName.at(tagName.length()-1) == '!'
        || tagName.at(tagName.length()-1) == ','
        || tagName.at(tagName.length()-1) == '.'
        || tagName.at(tagName.length()-1) == '?'){
            throw std::invalid_argument("");
    }
    for(unsigned int i = 0; i < tagName.length(); i++){
        if(tagName.at(i) >= 'A' && tagName.at(i) <= 'Z'){
            throw std::invalid_argument("");
        }
    }
}

string Tag::getTagName() {
    // TODO: implement getter
    return tagName;

}

vector<Post*>& Tag::getTagPosts() {
    // TODO: implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
    // TODO: add post to tag posts
    if(post == nullptr){
        throw std::invalid_argument("");
    }
    tagPosts.push_back(post);
}
