class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  //For lex order
        
        vector<vector<string>>list;
        string c = "";
        
        for(int i=0; i<searchWord.length(); i++){
            c = c + searchWord[i];
            
            vector<string> a;
            for(int j = 0; j<products.size(); j++){
                string match = products[j].substr(0, c.length());
                
                if(match == c){
                    a.push_back(products[j]);
                }
                
                if(a.size()==3){
                    break;
                
               }
                
            }
            list.push_back(a);
        }
        return list;
    }
};