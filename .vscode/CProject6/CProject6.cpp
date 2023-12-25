#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <clocale>
#include <time.h>
#include <cstring>
using namespace std;

struct student
{
	char* lastname;
	char* name;
	char* faculty;
	int num_group;
};

//Функция заполнения данных об одном студенте
void input(student *arr, int number) {
	char buff[30];
	//Добавление фамилии
	cout << "Введите фамилию: ";
    cout << "Введите фамилию: ";



    
	cin >> buff;
	arr[number].lastname = new char[strlen(buff) + 1];
	strcpy(arr[number].lastname, buff);
	//Добавление имени
	cout << "Введите имя: ";
	cin >> buff;
	arr[number].name = new char[strlen(buff) + 1];
	strcpy(arr[number].name, buff);
	//Добавление названия направления подготовки
	cout << "Введите название направления подготовки: ";
	cin >> buff;
	arr[number].faculty = new char[strlen(buff) + 1];
	strcpy(arr[number].faculty, buff);
	//Добавление номера группы
	cout << "Введите номер группы: ";
	cin >> buff;
	arr[number].num_group = atoi(buff);
}

//Функция добавление студента (т.е. увеличение массива)
void add(student* students, int quantity_students) {
	students = (student*)realloc(students, sizeof(student) * (quantity_students));
}

//Функция вывода инфорации о студенте в форме таблицы
void output(student* arr, int number, int type) {
    //Type: 1 Вывод number+1 студента с названием столбоц
    //Type:2 Вывод number+1 студента без названия столбцов
    //В ином случае выводятся все студенты с названием сстолбцов
	if (type == 1) {
		cout << "--------------------------------------------------------------\n";
		cout << left << setw(20) << "| Lastname"
			<< left << setw(15) << "| Name"
			<< left << setw(10) << "| Faculty"
			<< left << setw(12) << "| № group" << " |\n";
		cout << "--------------------------------------------------------------\n";
		cout << left << "| " << left << setw(17) << arr[number].lastname
				<< left << " | " << left << setw(12) << arr[number].name
				<< left << " | " << left << setw(7) << arr[number].faculty
				<< left << " | " << left << setw(10) << arr[number].num_group << " |\n";
		cout << "--------------------------------------------------------------\n";
	}
	else if (type ==2) {
		cout << left << "| " << left << setw(17) << arr[number].lastname
				<< left << " | " << left << setw(12) << arr[number].name
				<< left << " | " << left << setw(7) << arr[number].faculty
				<< left << " | " << left << setw(10) << arr[number].num_group << " |\n";
		cout << "--------------------------------------------------------------\n";
	}
	else {
		cout << "--------------------------------------------------------------\n";
		cout << left << setw(20)<<"| Lastname"
			<< left<< setw(15) << "| Name" 
			<< left<< setw(10) << "| Faculty" 
			<< left << setw(12) << "| № group" << " |\n";
		cout << "--------------------------------------------------------------\n";
		for (int i = 0; i < number; i++)
		{
			cout << left << "| " << left << setw(17) << arr[i].lastname
				<< left <<  " | " << left << setw(12) << arr[i].name
				<< left << " | " << left << setw(7) << arr[i].faculty
				<< left << " | " << left << setw(10) << arr[i].num_group << " |\n";
		}
		cout << "--------------------------------------------------------------\n";
	}
}

//Функция вывода инфорации о студенте в форме таблицы
void output_by_faculty(student* arr, int number, char * name_faculty){
    cout << "--------------------------------------------------------------\n";
	cout << left << setw(20)<<"| Lastname"
			<< left<< setw(15) << "| Name" 
			<< left<< setw(10) << "| Faculty" 
			<< left << setw(12) << "| № group" << " |\n";
	cout << "--------------------------------------------------------------\n";
    for (int i =0;i<number;i++){
        if (strcmp(arr[i].faculty, name_faculty)==0){
            output(arr, i, 2);
        }
    }
}

//Функция вывода инфорации о студенте в форме таблицы
void output_by_faculty_and_group(student* students, int number, char * name_faculty, int number_of_group){
    student *selected_group;
    int quantity = 1;
    selected_group=(student*)malloc(sizeof(student) * quantity);
    for (int i =0; i<number; i++){
        if ((students[i].num_group == number_of_group) && (students[i].faculty == name_faculty)){
            quantity++;
            add(selected_group, quantity);
            input(selected_group, quantity-1);
        }
    }
    output(selected_group, quantity, 0);
    //student *help;
    //help=(student*)malloc(sizeof(student) * 1);
    for (int i =0; i<quantity; i++)
    {
        for (int j=i+1;j<quantity;j++){
            if (strcmp(selected_group[i].lastname, selected_group[j].lastname)>0){
                swap(selected_group[i], selected_group[j]);
            }
            if (strcmp(selected_group[i].lastname, selected_group[j].lastname)==0){
                if (strcmp(selected_group[i].name, selected_group[j].name)==0){
                    swap(selected_group[i], selected_group[j]);
            }
            
        }
    }
    output(selected_group, quantity, 0);
    //удалить массив
    }
}

//memcpy(&help, &user, sizeof(user));


/// <summary>
/// для 6 сделать удаление массивла студентов
/// https://stackoverflow.com/questions/23982583/using-realloc-for-array-of-structs
/// https://www.cyberforum.ru/c-beginners/thread1165306.html
/// сделать еще 2 функции
/// Определить, почему при такой программе не хочет работать вывод в табличном виде
///определить,п очему не работает output_by_faculty, если есть добавленный студент
/// </summary>
/// <returns></returns>

int main() {

	setlocale(LC_ALL, "rus");
	cout << "" << endl;
	cout << "_______________________________________" << endl;
	int check = 1;
	int quantity_students;
	cout << "Введите количество студентов:" << endl;
	cin >> quantity_students;
	//Создание динамического массива с данными студентов
	student* students;
	students=(student*)malloc(sizeof(student) * quantity_students);
	//Заполнение массива студентов
	for (int i = 0; i < quantity_students; i++) {
		input(students, i);
		cout << endl;
	}

	do {
		cout << "_______________________________________" << endl;
		cout << "Выберите действие: " << endl;
		cout << "1 - Добавить нового студента" << endl;
		cout << "2 - Вывод информации об одном студенте" << endl;
		cout << "3 - Вывод информации про всех студентов" << endl;
		cout << "4 - Вывод всех студентов по заданному направлению подготовки"<< endl;
		cout << "5 - Вывод всех студентов заданной группы"<< endl;
		cout << "6 - Выйти из программы" << endl;		
		cin >> check;
		switch (check ){
		case 1: quantity_students++; add(students, quantity_students); input(students, quantity_students-1); break;
		case 2: {
			int val;
			cout << "\nВведите номер по счету студента" << endl;
			cin >> val;
			output(students, val-1, 1);
			break;
		}
		case 3: cout<<quantity_students; output(students, quantity_students, 0); break;
		case 4: {
		    //cout<<"Выберите направление подготовки из списка: "<<endl;
		    //char len_faculties[50];
	
		    //for (int i =0;i<quantity_students;i++){
		        //if (len_faculties.find(students[i].faculty)==0) strcat(len_faculties, students[i].faculty);
		    //}
		    //cout<<len_faculties<<"\t";
		    cout<<"Выберите направление подготовки: "<<endl;
		    char name_faculty[30];
		    cin>>name_faculty;
		    output_by_faculty(students, quantity_students, name_faculty);
		    
		}
		case 5: {
		    cout<<"Выберите направление подготовки: "<<endl;
		    char name_faculty[30];
		    cin>>name_faculty;
		    cout<<"Выберите номер группы: "<<endl;
		    int number_of_group;
		    cin>>number_of_group;
		    output_by_faculty_and_group(students, quantity_students, name_faculty, number_of_group);
		    
		}
		case 6: check = 6; break;
		}


	} while (check !=6);
	system("pause");
	return 1;
}





//#include <iostream>
//#include <iomanip>
//#include <clocale>
//#include <time.h>
//using namespace std;
//#define N 5
//
//int main() {
//
//	setlocale(LC_ALL, "rus");
//	int check = 1;
//	do {
//
//		cout << "\nЖелаете еще раз выполнить программу? 1 - да, 0 - нет" << endl;
//		cin >> check;
//
//	} while (check == 1);
//	system("pause");
//	return 1;
//}


//
//void killDynArray(dynArray* x)
//{
//	if (x->a) free(x->a);
//	x->count = x->size = 0;
//	x->a = NULL;
//}