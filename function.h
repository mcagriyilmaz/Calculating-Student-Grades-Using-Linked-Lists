struct nodeClass{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

struct nodeClass nodeClass;
struct nodeStudent nodeStudent;


void computeClassAverage(struct nodeClass *root){
	struct nodeClass *iter;
	struct nodeStudent *istudent;
	double sum=0;
	int count=0;
	iter = root;
	
	while(iter != NULL){
		istudent = iter ->studentPtr;
		while(istudent != NULL){
			sum += istudent -> midterm;
			count++;
			istudent = istudent->next;
		}
		iter ->classMidtermAverage = sum / count;
		sum = 0;
		count = 0;
		iter = iter -> next;
	}
}

void printAll(struct nodeClass *root){
	struct nodeClass *iter;
	struct nodeStudent *istudent;
	iter = root;
	while(iter != NULL){
		istudent = iter -> studentPtr;
		printf("%d %.2f\n",iter->classID,iter->classMidtermAverage);
		while(istudent != NULL){
			printf("%d %d\n",istudent->studentID,istudent->midterm);
			istudent = istudent->next;
		}
		iter = iter->next;
	}
}

void sort_insert(struct nodeClass *iter, int id, int vize){
	struct nodeStudent *istudent = iter ->studentPtr;
	struct nodeStudent *temp = NULL;
	if(istudent == NULL){
		istudent = (struct nodeStudent*)malloc(sizeof(nodeStudent));
		istudent -> studentID = id;
		istudent -> midterm = vize;
		istudent -> next = NULL;
		iter -> studentPtr = istudent;
		return;
	}
	if(istudent -> midterm <= vize){
		if(istudent->midterm == vize && istudent->studentID < id){
			temp = (struct nodeStudent*)malloc(sizeof(nodeStudent));
			temp -> studentID = id;
			temp -> midterm = vize;
			temp -> next = istudent -> next;
			istudent ->next = temp;
			return;
		}
		else{
			temp = (struct nodeStudent*)malloc(sizeof(nodeStudent));
			temp -> studentID = id;
			temp -> midterm = vize;
			temp -> next = istudent;
			istudent = temp;
			iter -> studentPtr = istudent;
			return;
		}
	}
	while(istudent->next != NULL && istudent-> next -> midterm > vize){
		istudent = istudent -> next;
	}
	if(istudent -> next == NULL){
		temp = (struct nodeStudent*)malloc(sizeof(nodeStudent));
		temp -> studentID = id;
		temp -> midterm = vize;
		temp -> next = istudent -> next;
		istudent ->next = temp;
		return;
	}
	if(istudent->next->midterm == vize && istudent->next->studentID < id){
		temp = (struct nodeStudent*)malloc(sizeof(nodeStudent));
		temp -> studentID = id;
		temp -> midterm = vize;
		temp -> next = istudent->next->next;
		istudent->next = temp;
		return;
	}
	else{
		temp = (struct nodeStudent*)malloc(sizeof(nodeStudent));
		temp -> studentID = id;
		temp -> midterm = vize;
		temp -> next = istudent -> next;
		istudent ->next = temp;
	}
}

void insert(struct nodeClass **rootptr, int id, int vize){
	struct nodeClass *root;
	root = *rootptr;
	if(root == NULL){
		struct nodeClass *iter;
		root = (struct nodeClass*)malloc(sizeof(nodeClass));
		root -> classID = 1;
		root -> studentPtr = NULL;
		iter = root;
		for(int i=2;i<5;i++){
			iter -> next = (struct nodeClass*)malloc(sizeof(nodeClass));
			iter = iter ->next;
			iter -> classID = i;
			iter -> next = NULL;
			iter -> studentPtr = NULL;
		}
		*rootptr = root;
	}

	struct nodeClass *iter;
	iter = root;
	
	int num = id;
	
	while(num > 100){
		num /= 10;
	}
	
	if(num==66){
		sort_insert(iter,id,vize);
	}
	if(num==77){
		iter = iter->next;
		sort_insert(iter,id,vize);
	}
	if(num==88){
		for(int i=0;i<2;i++){
			iter = iter->next;
		}
		sort_insert(iter,id,vize);
	}
	if(num==99){
		for(int i=0;i<3;i++){
			iter = iter->next;
		}
		sort_insert(iter,id,vize);
	}
}


// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.
