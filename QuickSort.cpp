/* Sort a given random array in ascending order. Steps are:
1] Pick first number of the array and count the total numbers that are smaller to it. 
2] Place the selected number on its correct place and partition the array arround it with smaller elements left to the selected no. and larger elements to the right.
3] Then call recurrsion function to do the same process on the left side of partition and right side of partition passing their starting index, ending index and the array itself.
4] Base case will be if end index is smaller or equal to starting index, it will return.
*/




#include<iostream>

using namespace std;

void swap(int s[], int i, int j){
    int temp = s[i];
    s[i]=s[j];
    s[j]=temp;
}

int partition(int input[], int si, int ei){
    int count=si-1;
    for(int i=si+1; i<=ei; i++){
        if(input[si]>=input[i]){
            count++;
        }
    }
    swap(input,si,count+1);
    int i=si;

   while( i<count+1){
       if(input[i]>=input[count+1]){
           int j=ei;
           while(j>count+1){
               if(input[j]<=input[count+1]){
                   swap(input, i, j);
                   break;
               }
               j--;
           }
       }
       i++;
   }
    return count+1;
}


void quickSort(int input[], int start, int end)
	{
    		// your code goes here
    if(end<=start){
        return;
    }
    int c = partition(input, start, end);
    quickSort(input,start, c-1);
    quickSort(input, c+1, end);
	}

void quickSort(int input[], int size) {
    // Change in the given array itself.
    quickSort(input, 0, size-1);

}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}
