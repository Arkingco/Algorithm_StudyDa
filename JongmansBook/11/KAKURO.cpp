#include<iostrea>
using namespace std;

int getSize(int mask);

int getSum(int mask);

int getCandudates(int len , int sum , int known){
	int allSets = 0;
	for(int set = 0; set < 1024; set +=2){
		if((set & known ) == known && getSize(set) == len && getSum(set) == sum){
			allSets |= set;
		}
	}
	return allSets & ~known;
}

int main(){
	
}