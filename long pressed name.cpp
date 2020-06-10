class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name[0] != typed[0]){
            return false;
        }
        int i = 1; 
        int j = 1;
        
        while(i < name.length() && j < typed.length()){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            else{
                if(typed[j] == typed[j-1]){
                    j++;
                }
                else{
                    return false;
                }
            }
        }
        if(j == typed.length() && i == name.length()){
            return true;
        }
        if(j == typed.length() && i != name.length()){
            return false;
        }
        if(i == name.length() && j != typed.length()){
            while(j !=typed.length()){
                if(typed[j] == typed[j-1]){
                    j++;
                }
                else{
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }
};