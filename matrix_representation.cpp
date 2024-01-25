#include <iostream>

using namespace std;
class myMatrix{ //I created a class which named myMatrix
	private:    //private member variables
		int r;  //represents rows
		int c;  //represents columns
		int **ptr;  //represents dynamic declaration of the matrix
	public:
		myMatrix():r(2),c(3){ 
		
		}
		myMatrix(int rows, int colomns) : r(rows), c(colomns) { //constructor with parameters
        ptr = new int* [r]; //allocates memory for rows
        for (int i = 0; i < r; ++i) {
            ptr[i] = new int [c]; //allocate memory for columns
        } 
    }
		~myMatrix(){ //it is a destructor. it frees the memory space which allocated for the object
			for(int i=0;i<r;i++)
			{
				delete[] ptr[i]; //deallocate memory for each row
			}
			delete[] ptr; //deallocate memory for the pointer array
		}	
		
		 void initializeMatrix(int r2,int c2) // in this function we take the values of the matrix from user
		{
			cout<<"enter matrix elements: "<<endl;
			for(int i=0;i<r2;i++) //rows
			{
				for(int j=0;j<c2;j++) // columns
				{
					cin>>ptr[i][j]; // it stores the values into pointer
				}
			}
			
			
		}
	     int getspecificElement(int x,int y)
	     {
	     	return ptr[x][y]; //it returns the value at specific location of the matrix
		 }
		 
		 bool putElementatSpecificLocation(int x,int y,int value){ // we will take row, column and element values from the user in the "main"
		 	if (x>=0 && x<=r && y>=0 && y<=c){ //rows and column values should be appropriate for being equal to index values
		 		ptr[x][y] = value; //entered value will be stored in variable value at location x,y
		 		return true; //if entered value stored succesfully it returns true
			 }
			 else{
			 	return false; // if not, false
			 }
		 }
		 
		 int calculateRowSum(){ 
		 	int maxsum=0;
		 	for(int i=0;i<r;i++){
		 		int rowsum=0;
		 		for(int j=0;j<c;j++){
		 			rowsum= rowsum + ptr[i][j];
				 }
				 if(rowsum>maxsum)
				 {
				 	maxsum=rowsum;
				 }
				 
			 }
			 return maxsum /c ; //this function will return highest average value
			 
			 
		 }
		 
		 void printMatrix(){
		 	for(int i=0;i<r;i++)
		 	{
		 		for(int j=0;j<c;j++)
		 		{
		 			cout<<ptr[i][j]<<" ";
				 }
				 cout<<endl;  //this function will print all rows and columns our matrix respectively
			 }
		 }
	
};
int main() {
	int r1,c1;  //r1 for rows, c1 for columns
	
	cout<<"***CREATE YOUR MATRIX***"<<endl;
	cout<<"enter number of rows: ";
	cin>>r1;
	cout<<"enter number of columns: ";
	cin>>c1; 
	
	myMatrix my(r1,c1); //I created an object which named "my", and I used constructor with rows and columns value that I take from the user
	
	my.initializeMatrix(r1,c1); //takes the matrix elements from user
	cout<<"***YOUR MATRIX:***"<<endl;
	my.printMatrix();  //prints them 
	int r3,c3,value; //variables for update operation
	cout<<"***UPDATE PART***"<<endl;
	cout<<"enter row and column and value to update respectively: ";
	cin>>r3>>c3>>value;
	my.putElementatSpecificLocation(r3,c3,value); //updating function
	bool yes = my.putElementatSpecificLocation(r3,c3,value); //function will return yes or no then bool value will be yes or no
	if(yes)
	{
		cout<<"value updated"<<endl;
	}
	else
	{
		cout<<"value could not be updated"<<endl;
	}
	cout<<"***NEW MATRIX***"<<endl;
	my.printMatrix(); //again, matrix will be printed
	int sum= my.calculateRowSum(); // and sum will be equal to result of the function
	cout<<"highest average value: "<<sum<<endl;
	cout<<"**GET SPECIFIC ELEMENT PART**"<<endl; // test for getspecificElement function
	int rows,columns;
	cout<<"enter row value: ";
	cin>>rows;
	cout<<"enter column value: ";
	cin>>columns;
	cout<<"your element: ";
	cout<<my.getspecificElement(rows,columns);
	
	return 0;
}
