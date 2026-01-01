#include<iostream>
using namespace std;


void membershipcheck(){
	int t_elements ,elmnt,n;
	bool found = false;
	int arr[200];
 cout << " How Many Number of Elements Wasa In Your Set ";
 cin >> t_elements;
 for ( int i =0 ; i < t_elements; i++){
 cout <<" Enter  no  "<<i+1<<" element : ";
 cout<<endl;
 cin>>arr[i];
 	
 	
 }
 cout<<" So Which Element Do You Want To Check :";
 cout<<endl;
 cin>>elmnt;
 for(int j =0 ; j >t_elements ; j++){
 	if(  arr[j] == elmnt){
 		found == true;
 		n = j;
 		break; 		
	 }
	
 }
 if (found == true){
 	cout << " The Element Exist In Your Set At "<<n+1<<"th Place " ;
 	cout << endl;
 }else if (found == false){
 	cout << " Elememt Doesen't found!! ";
 	cout <<endl;
 }
 	
}  


void removeduplicates(){
	int n;
	int arr[200];

	cout << " How Many Elements Are In Your Set: ";
	cin >> n;

	// Input elements
	for(int i = 0; i < n; i++){
		cout << " Enter element " << i+1 << ": ";
		cin >> arr[i];
	}

	// Removing duplicates
	int newSize = 0;
	int temp[200];

	for(int i = 0; i < n; i++){
		bool duplicate = false;
		for(int j = 0; j < newSize; j++){
			if(arr[i] == temp[j]){
				duplicate = true;
				break;
			}
		}

		if(!duplicate){
			temp[newSize] = arr[i];
			newSize++;
		}
	}

	// Output unique elements
	cout << "\n Set After Removing Duplicates: ";
	for(int i = 0; i < newSize; i++){
		cout << temp[i] << " ";
	}
	cout << endl;
}



void Union() {
    int n1, n2;
    int A[200], B[200], U[400];
    int k = 0;

    cout << "Enter number of elements in Set A: ";
    cin >> n1;
    cout << endl;

    // Input Set A
    for (int i = 0; i < n1; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }

    cout << "\nEnter number of elements in Set B: ";
    cin >> n2;
    cout << endl;

    // Input Set B
    for (int i = 0; i < n2; i++) {
        cout << "B[" << i + 1 << "] = ";
        cin >> B[i];
    }

    // Step 1: Copy Set A into Union Set
    for (int i = 0; i < n1; i++) {
        U[k++] = A[i];
    }

    // Step 2: Add only unique elements from Set B
    for (int i = 0; i < n2; i++) {
        bool found = false;

        // Check if B[i] already exists in U
        for (int j = 0; j < k; j++) {
            if (B[i] == U[j]) {
                found = true;
                break;
            }
        }

        // If not found, add it
        if (!found) {
            U[k++] = B[i];
        }
    }

    // Display UNION
    cout << "\nUnion of Set A and Set B is: { ";
    for (int i = 0; i < k; i++) {
        cout << U[i] << " ";
    }
    cout << "}" << endl;
}



void Intersection() {
    int n1, n2;
    int A[200], B[200], I[200];
    int k = 0;

    cout << "Enter number of elements in Set A: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }

    cout << "\nEnter number of elements in Set B: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "B[" << i + 1 << "] = ";
        cin >> B[i];
    }

    // Find matching elements
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                I[k++] = A[i];
                break;
            }
        }
    }

    // Display
    cout << "\nIntersection of A and B is: { ";
    for (int i = 0; i < k; i++) {
        cout << I[i] << " ";
    }
    cout << "}" << endl;
}


void compilement() {
    int nU, nA;
    int U[200], A[200], C[200];
    int k = 0;

    cout << "Enter number of elements in UNIVERSAL SET: ";
    cin >> nU;
    for (int i = 0; i < nU; i++) {
        cout << "U[" << i + 1 << "] = ";
        cin >> U[i];
    }

    cout << "\nEnter number of elements in Set A: ";
    cin >> nA;
    for (int i = 0; i < nA; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }

    // -------------------------
    // REMOVE DUPLICATES IN U
    // -------------------------
    int newU[200], uCount = 0;
    for (int i = 0; i < nU; i++) {
        bool exist = false;
        for (int j = 0; j < uCount; j++) {
            if (U[i] == newU[j]) {
                exist = true;
                break;
            }
        }
        if (!exist)
            newU[uCount++] = U[i];
    }

    // -------------------------
    // REMOVE DUPLICATES IN A
    // -------------------------
    int newA[200], aCount = 0;
    for (int i = 0; i < nA; i++) {
        bool exist = false;
        for (int j = 0; j < aCount; j++) {
            if (A[i] == newA[j]) {
                exist = true;
                break;
            }
        }
        if (!exist)
            newA[aCount++] = A[i];
    }

    // -------------------------
    // COMPLEMENT = U - A
    // -------------------------
    for (int i = 0; i < uCount; i++) {
        bool found = false;
        for (int j = 0; j < aCount; j++) {
            if (newU[i] == newA[j]) {
                found = true;
                break;
            }
        }

        if (!found)
            C[k++] = newU[i];
    }

    // -------------------------
    // DISPLAY RESULT
    // -------------------------
    cout << "\nComplement of A (U - A) is: { ";
    for (int i = 0; i < k; i++) {
        cout << C[i] << " ";
    }
    cout << "}" << endl;
}



void difference() {
    int n1, n2;
    int A[200], B[200], D[200];
    int k = 0;

    cout << "Enter number of elements in Set A: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }

    cout << "\nEnter number of elements in Set B: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "B[" << i + 1 << "] = ";
        cin >> B[i];
    }

    // Elements in A that are NOT in B
    for (int i = 0; i < n1; i++) {
        bool found = false;

        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            D[k++] = A[i];
        }
    }

    // Display
    cout << "\nDifference (A - B) is: { ";
    for (int i = 0; i < k; i++) {
        cout << D[i] << " ";
    }
    cout << "}" << endl;
}

int main(){
	int choice;
	do{
		system("cls");
		cout << "========================================"; 
		cout<<endl;
		cout << "|- - - -  SET OPERATION SYSTEM - - - - |"<<endl;
		 cout << "========================================";
		 cout<<endl;
		
		cout << "1. Membership Check";
			cout<<endl; 
		cout << "2. Remove Duplicates";
			cout<<endl; 
		cout << "3. Union of Two Sets";
			cout<<endl; 
		cout << "4. Intersection of Two Sets";
			cout<<endl; 
		cout << "5. Difference of Two Sets";
			cout<<endl;
		 cout << "6. Complement of a Set"; 
		 	cout<<endl;
		 cout << "7. Exit";
		 
		 	cout<<endl; 
		cout << "----------------------------------------";
		cout<<endl;
		cout<<" enter your choice 1-7 :";
			cout<<endl;
			cin>>choice;
		switch(choice){
			case 1:{
				membershipcheck();
				break;
			}
			case 2:{
				removeduplicates();
				
				break;
			}
			case 3:
			{
				Union();
				break;
			}
			case 4:{
				Intersection();
				break;
			}
			case 5:{
				difference();
				break;
			}
		
			case 6:{
			compilement();
				break;
			}
				default :
			{
				cout<<" Ivalid choice !! Enter again ";
				cout<<endl;
			} 
				
		}

				if(choice !=7){
				cout<<" Press Enter To Continue ";
				cout<<endl;
				cin.ignore();
				cin.get();
			}
		
	}while(choice!=7);
	
	
	
	
	
	
	return 0;
}