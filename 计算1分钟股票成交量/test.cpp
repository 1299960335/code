class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param timestamp string字符串vector 
     * @param volume int整型vector 
     * @return string字符串vector
     */
    vector<string> sumVolume(vector<string>& timestamp, vector<int>& volume) {
       vector<string> vs;
        size_t size = timestamp.size();
        int num = 0;
        int i = 0;
        int pos = timestamp[0].rfind(':');
        string s = timestamp[0].substr(0,pos);
        while(i < timestamp.size()){
            if(timestamp[i].find(s) != s.npos){
                num += volume[i];
                i++;
            }
            else{
                s = s + ',' + to_string(num);
                vs.push_back(s);
                num = 0;
                pos = timestamp[i].rfind(':');
                s = timestamp[i].substr(0,pos);
            }
        }
        if(timestamp[size - 1].find(s) != s.npos){
                s = s + ',' + to_string(num);
                vs.push_back(s);
        }
        return vs;
    }
};