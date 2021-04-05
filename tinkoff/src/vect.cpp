#include"vect.h"


bool isnum(std::string s){
    try{
        std::stoi(s);
    }
    catch (std::invalid_argument &)
    {return false;}
    return true;
}


bool is_valid(std::shared_ptr<std::vector<std::string>> v){
    std::string digit = "";
    for (auto &x : *v){
        if (isnum(x))
        {
            if(digit != ""){
                if (x != digit){  // Inconsistency
                    return false;
                }
                else{  // x is good;
                    continue;
                }
            }
            else{  // First appearance of digit
                digit = x;
            }
        }
    }
    return true;
}


bool fill_check(std::vector<std::string> s1, std::vector<std::string> s2){
    int n = s1.size();
    std::map<std::string, std::shared_ptr<std::vector<std::string>>> dict;
    for (int i = 0; i < n; ++ i) {
        auto a = s1[i];
        auto b = s2[i];
        if (!dict[a] && !dict[b]){
            dict[a] = std::make_shared<std::vector<std::string>>();
            dict[a]->push_back(a);
            dict[a]->push_back(b);
            dict[b] = dict[a];
        }
        else if (!dict[a]){
            dict[b]->push_back(a);
            dict[a] = dict[b];
        }
        else if (!dict[b]){
            dict[a]->push_back(b);
            dict[b] = dict[a];
        }
        else{
            if (dict[a] != dict[b]){
                dict[a]->insert(std::end(*dict[a]), std::begin(*dict[b]), std::end(*dict[b]));
                std::shared_ptr<std::vector<std::string>> temp = dict[b];
                for(std::string &x: *dict[b]){
                    dict[x] = dict[a];
                }
                // We would like to delete the old b vector it pointed to 
                // delete temp;
                // Destructor should be called by smart_ptr
            }
            else {
                continue;
            }
        }
    }
    for(auto & item: dict){
        if (!is_valid(item.second)) return false;
    }
    return true;
}


/*
int main(void){
    int n;
    std::cin >> n;
    std::vector<std::string> s1(n);
    std::vector<std::string> s2(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> s1[i];
    }
    for (int i = 0; i < n; ++ i) {
        std::cin >> s2[i];
    }
    bool res = fill_check(s1, s2);
    std::cout << res ? "NO": "YES";
}
*/
