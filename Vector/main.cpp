# include <iostream> // cout for debugging and checking things

using namespace std;// allows for not typing std:: in front of things like cout 

class intVector
{
  public:
  // constructor destructor 
  
  intVector();
  ~intVector();
  // varibles 
  int size = 1; // current max size of the array
  int capacity = 0; // number of things in the array
  
  //functions 
  void push_back(int a);//adds given int to the back of the vector
  void shrink_to_fit();//shriks the vector size to match capacity
  void print_vector() const;// print vector, size, capacity
  void push_front(int b);// put in front of array
  void resize(int c);// resize to user defined size 
  void sort(int* p, int size);//sorts vector using merge sort
  void insert(int val, int pos); //given a intger value and a postion insert into the vector
  void remove(int pos);//given a postion remove the value at that postion and then shift everything after it over 1
  void clear();//clears all the values from the vector, keeps the size but sets capacity to zero
  bool is_empty() const;//checks if vector is empty(capacity = 0) if it is returns true, if it's not returns false
  int* getVectorPointer() const;//gets the pointer to the vector 

  
  private:
  void resize();//doubles the array size 
  int* storeValues(int pos, int tempSize);//given a postion to start transfering value and a size for the new vector stores values from an old vector. 
  int* p;//pointer to the start of the vector
  
};
//////////////////////////////////////////////////////
intVector::intVector()
{
  cout << "constructed" << endl;
  p = new int[size];
}

intVector::~intVector()
{
  cout << "destroyed" << endl;
  delete[] p;
}

void intVector::push_back(int a)
{
  if (capacity == size)
  {
    resize();
  }
 
  p[capacity] = a;
  capacity++;

}

void intVector::push_front(int b)
{
  if (capacity == size)
  {
   resize(); 
  }
  

  int* tempArray = new int[size]; // make a new array 
  tempArray[0] = b;
  for(int i = 0; i < capacity; i++)
  {
    tempArray[i+1] = p[i];
  }
  
  capacity++;
  
  //sets empty spaces at end of vector to zero 
  int tempInt = size - capacity;
  for (int j = 0; j < tempInt; j++)
  {
    tempArray[capacity + j] = 0;
  }
  
  delete[] p;
  p = tempArray;
}

void intVector::resize(int c)
{
  if (c < capacity)
  {
    cout << "New vector is too small. Some data will be lost." << endl;
    capacity = c;
  }
  
  size = c;
  int* tempArray = new int[c];// make a new array the size of c 
  
  for (int i = 0; i < capacity; i++)
  {
    tempArray[i] = p[i];  
  }
  
  //sets empty spaces at end of vector to zero 
  int tempInt = size - capacity;
  for (int j = 0; j < tempInt; j++)
  {
    tempArray[capacity + j] = 0;
  }
  
  delete[] p;
  p = tempArray; 
}

void intVector::sort(int* p, int size)
{
  //make a break case
  if(size == 2)
  {
    if(p[0] > p[1])
    {
      int temp = p[0];
      p[0] = p[1];
      p[1] = temp;
      cout << "sort" << endl;
      cout << p[0] << endl;
      cout << p[1] << endl;
      return; 
    }
    cout << "Break" << endl;
    cout << p[0] << endl;
    cout << p[1] << endl;
  return;
  }
  else if (size == 1)
  {
    return;
  }
  
  int smallSizeA, smallSizeB;
  
  if(size % 2 == 0)
  {
     smallSizeA = size/2;
     smallSizeB = size/2;
    cout << "small sizes:" << endl;    
    cout << smallSizeA << endl;
    cout << smallSizeB << endl;
  }
  else 
  {
     smallSizeA = size/2;
     smallSizeB = (size/2) + 1;
     cout << "small sizes:" << endl;    
    cout << smallSizeA << endl;
    cout << smallSizeB << endl;
  }
  
  //make two new arrays to hold the halves of the first array
  int* arryA = new int[smallSizeA];
  int* arryB = new int[smallSizeB];
  
  //this puts the elements of the first array into the two new arrays 
  for(int i = 0; i < size; i++)
  {
    if (i < smallSizeA)
    {
      arryA[i] = p[i];
    }
    else
    {
      arryB[i-smallSizeA] = p[i];
    }
  }
  
  
  //printing unsorted arrays 
  cout<< "arryA:" << endl;
  for(int j = 0; j < smallSizeA; j++)
  {
   cout<< arryA[j] << endl;
  }
  cout<< "arryB:" << endl;
  for(int k = 0; k < smallSizeB; k++)
  {
   cout<< arryB[k] << endl;
  }
  //add recursion
    
  sort(arryA, smallSizeA);
  sort(arryB, smallSizeB);
  //write merge function 
  
  int i = 0, j = 0;
  while(i < smallSizeA && j < smallSizeB)
  {
    if (arryA[i] < arryB[j])
    {
      p[i+j] = arryA[i];
      i++;

    }      
    else 
    {
      p[i+j] = arryB[j];
      j++;

    }
  }
  
  if(i == smallSizeA)
  {
    while(j < smallSizeB)
    {
      p[i+j] = arryB[j];
      j++;
    }
  }
  
  if(j == smallSizeB)
    {
      while(i < smallSizeA)
      {
      p[i+j] = arryA[i];
      i++;
      }
    }
  delete[] arryA;
  delete[] arryB;  
}

void intVector::shrink_to_fit()
{
  int* temp_array = new int[capacity];
  
  for (int k = 0; k < capacity; k++)
  {
    temp_array[k] = p[k];
  }
  
  size = capacity;
  delete[] p;
  p = temp_array;
}

void intVector::print_vector() const
{
  //print the size and capacity of the vector
  cout << "Size:" << size << endl;
  cout << "Capacity:" << capacity << endl;
  
  
  for (int i =0; i < size; i++)
  {
    cout<< p[i] << endl;
  }
}

void intVector::clear()
{
  cout << "vector cleared" << endl;
  
  //resets all vector values to zero
  for(int i = 0; i < size; i++)
  {
    p[i] = 0;
  }
  
  capacity = 0;//set capacity back to zero
}

bool intVector:: is_empty() const
{
  bool isempty = false;
  
  if(capacity == 0)
  {
    isempty = true; 
  }
  
  cout << "ran is empty" << endl;
  cout << isempty << endl;
  
  return isempty;
}

void intVector::insert(int val, int pos)
{
  //check and see if pos is greater than vector size
  //if it is resize until it's not 
  if(pos > size || pos == capacity)
  {
   while(pos >= size)
   {
     resize();
   }
  }
  
  // going to need to store all values at and to the right of the postion in a temp array
  if(pos < capacity)
  {
    cout << "pos < capacity" << endl;
  //need size of new temp array(capacity - pos)
  int tempSize = capacity - pos;
  cout << "Temp Size:" << tempSize << endl;
  //get values to store
  int* temp = storeValues(pos, tempSize); 
  
  for(int i = 0; i < tempSize; i++)
  {
    p[pos + 1 + i] = temp[i];
  }
  
  }
  //overwrite postion with given value
  p[pos] = val;  
  capacity++;
  //put the rest of the values 
  
}

void intVector::remove(int pos)
{
  //check postion against size 
  //if it's greater return 
  if(pos > size)
  {
    cout << "position not in vector" << endl; 
    return; 
  }
  
  p[pos] = 0;
  
  //if there were values after the deleted value
  if(pos < capacity)
  {
    //need size of new temp array(capacity - pos)
    int tempSize = capacity - pos;
    cout << "Temp Size:" << tempSize << endl;
    int tempPos = pos + 1;
    int* temp = storeValues(tempPos, tempSize);
    //make a temp array with values 
     for(int i = 0; i < tempSize; i++)
    {
      p[pos + i] = temp[i];
    }
    p[capacity - 1] = 0;
  }
  capacity--;
}

int* intVector::getVectorPointer() const
{
  return p;

  }
void intVector::resize()
{
  int temp = size;// holds the intial size of the array
  size = temp * 2;// doubles size 
  int* tempArray = new int[size];
  
  for (int i = 0; i < temp; i++)
  {
    tempArray[i] = p[i];
  }
  
   //sets empty spaces at end of vector to zero 
  int tempInt = size - capacity;
  for (int j = 0; j < tempInt; j++)
  {
    tempArray[capacity + j] = 0;
  }
  delete[] p;
  p = tempArray;
 
}

int* intVector::storeValues(int pos, int tempSize)
{
  //need size of new temp array(capacity - pos)
  //int tempSize = capacity - pos
  //cout << "Temp Size:" << tempSize << endl;
  cout << "storing temp values" << endl;
  //make an array to store the values
  int* temp = new int[tempSize];
  
  //copy p[pos + i + 1] to the new array 
  for(int i = 0; i < tempSize; i ++)
  {
   temp[i] = p[pos + i]; 
  }    


  //return the pointer to the new array 
  return temp;
}


int main(void)
{
  intVector test;
  //test.is_empty();
  
  test.push_back(4);
  test.push_back(2);
  test.push_back(1);
  test.push_back(3);
  test.push_back(7);
  test.push_back(6);
  test.push_back(8);
  test.push_back(5);
  test.push_front(9);
  test.shrink_to_fit();
  test.sort(test.getVectorPointer(), test.size);
  test.print_vector();
  
  test.remove(8);
  test.print_vector();
  
  test.remove(5);
  test.print_vector();
  test.remove(0);
  test.print_vector();
  test.insert(11, 2);
  test.print_vector();  
  test.remove(30);
  test.print_vector();
  //test.is_empty();
  //test.sort(test.p, test.size);
  //test.print_vector();
  //test.clear();
  //test.is_empty();
  //test.print_vector();
  
  return 0;  
}