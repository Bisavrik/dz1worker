#ifdef INTEGER
#define Worker
#define isValidNumber
#define addWorker
#define showWorker
#define deleteWorker
#define showAllWorkers
#define searchBySurname
#define searchBySalary
#define sortBySurname
#define writeToFile
#define readFromFile
#endif


struct Worker;
bool isValidNumber(const char* phoneNumber);
void addWorker(Worker& worker);
void showWorker(Worker& worker);
void deleteWorker(Worker* listWorker, int& sum);
void showAllWorkers(Worker* listWorker, int sum);
Worker* searchBySurname(Worker* listWorker, int sum, char* findSurname);
Worker* searchBySalary(Worker* listWorker, int sum);
void sortBySurname(Worker* listWorker, int sum);
void writeToFile(Worker* listWorker, int sum);
void readFromFile();


