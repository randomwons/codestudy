#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> divideAll(vector<int> array){
    vector<int> divides;
    
    int min = *min_element(array.begin(), array.end());
    for(int i = 2; i <= min; i++){
        bool isDivide = true;
        for(int j = 0; j < array.size(); j++){
            if (array[j] % i != 0) {
                isDivide = false;
                break;
            }
        }
        if (isDivide) divides.push_back(i);
    }
    return divides;
}

int dividesNo(vector<int> array, vector<int> divides){
    int max = 0;
    for(int divide : divides){
        bool isDivide = false;
        for(int v : array){
            if (v % divide == 0) {
                isDivide = true;
                break;
            }
        }
        if (!isDivide) {
            if (max < divide) max = divide;
        }
    }
    return max;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    vector<int> dividesAllA = divideAll(arrayA);
    vector<int> dividesAllB = divideAll(arrayB);
    
    int a = dividesNo(arrayA, dividesAllB);
    int b = dividesNo(arrayB, dividesAllA);
    
    return (a > b) ? a : b;
}