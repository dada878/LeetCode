"Link: https://leetcode.com/problems/roman-to-integer/"

/**
 * @param {string} s
 * @return {number}
 */
 var romanToInt = function(s) {
    
    const table = {
        "I":1,
        "V":5,
        "X":10,
        "L":50,
        "C":100,
        "D":500,
        "M":1000,
    };
    
    let result = 0;
    let i = 0; //index
    
    while (i < s.length) {
        
        let txt = s[i];
        let txt2 = s[i+1];
        
        if (i + 1 != s.length) {
            if (table[txt] >= table[txt2]) {
                result += table[txt];
                i++;
            } else {
                let num = table[txt2] - table[txt];
                result += num;
                i += 2;
            };
        } else {
            result += table[txt];
            i++;
        };
    };
    
    return result;
};