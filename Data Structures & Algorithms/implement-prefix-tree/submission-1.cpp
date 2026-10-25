struct TrieNode{
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};
class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i]-'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';

            if(curr->children[index]== nullptr){
                return false;
            }
            curr = curr->children[index];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';

            if(curr->children[index]== nullptr){
                return false;
            }
            curr = curr->children[index];
        }

        return true;
    }
};
