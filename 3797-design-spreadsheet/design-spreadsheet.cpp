class Spreadsheet {
public:
    unordered_map<string, unsigned> mp;
    Spreadsheet(int rows) {
    
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
        int m=formula.find('+');
        int x, y;
        if (formula[1]>='A') x=mp[formula.substr(1, m-1)];
        else x=stoi(formula.substr(1, m-1));
        if (formula[m+1]>='A') y=mp[formula.substr(m+1)];
        else y=stoi(formula.substr(m+1));
        return x+y;
    }
};

