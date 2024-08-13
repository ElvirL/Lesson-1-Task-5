/*
������� 5. ���������� ���� ����? ���? �����?�
��� ����� �������
���������� ������� ������ ���������������� ���� ����? ���? �����?�.
��� ���������� ����
� ������ ������� ���� ������ ������� ������, �� ���� �������� ������ �� �����, ������� ������ ������. ����� ����� �������� 13. 
������ ���������� ���: � ���������� �������� ����� (��������) ������������ �������� ������� �� ��������. ������ �� ����� ������ 
����������� ����� �������� ������, ������� � ����� ������ � ���� ����. ���� �������� ������ ��� �����, �������� ��������� �� 
�������� �� ���. � ������ ���� ���� ������� ����������� �� ������ �������.

��� ������ ������ �����-�� �� ��������, � ���� ������ ������ � �������� � �� ���� ����������� �� ����� ������� �������. 
������ ������������ �� ������.
����� ���� ��� ������ �������, �� ������ ��������� ����� �� ����. ����� ������ ���� ����� � ������� ������������ �����. 
��, ��� �� ���, ������������ � �������, ������� �������� �� ������ �����, ��������������� � �������� ��������. 
������ ���� ������ ��������� ���� ���� �����-�����.

���� ����� �������-������ ��� ����������, ��� ����������� ���� ����. ���� �������, �� ���� ������ ������������.
���� ������������ �� ��� ���, ���� ��� �����, ��� ������� �� ������� ����� ������. ����� ����� ���������� ���������� � ��������� 
����������� ������.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void choice_sector(bool game_sector[13], int& current_sector){
    cout << "������� �������� ������� ��������: ";
    int shift;
    cin >> shift;
    current_sector = (current_sector + shift) % 13;
    while (game_sector[current_sector-1]){
        current_sector = (current_sector +1) % 13;
    }
    game_sector[current_sector-1] = true;
    cout << "������ � " << current_sector << endl;
}

bool get_question_check_answer(const int& current_sector){
    string questions[13] = {"question1.txt", "question2.txt","question3.txt","question4.txt","question5.txt",
                            "question6.txt","question7.txt","question8.txt","question9.txt","question10.txt",
                            "question11.txt","question12.txt","question13.txt"};

    ifstream question_file;
    question_file.open(questions[current_sector-1]);
    cout << "������: ";

    while (!question_file.eof()){
        char buffer[20];
        question_file.read(buffer, sizeof(buffer));
        for (int i=0; i<question_file.gcount(); ++i){
            cout << buffer[i];
        }
    }
    cout << endl;

    question_file.close();

    cout << "������� ����� �� ������: ";
    string answer_gamer;
    cin >> answer_gamer;

    ifstream answer_file;
    string answers[13] = {"answer1.txt", "answer2.txt","answer3.txt","answer4.txt","answer5.txt",
                            "answer6.txt","answer7.txt","answer8.txt","answer9.txt","answer10.txt",
                            "answer11.txt","answer12.txt","answer13.txt"};    

    answer_file.open(answers[current_sector-1]);
    
    string answer;
    answer_file >> answer;
    answer_file.close();

    if (answer == answer_gamer){
        cout << "����� ������" << endl;
        return true;
    }
    cout << "����� ��������" << endl;
    return false;
}

int main(){
    setlocale(LC_ALL, "Russian");
     bool game_sectors[13] = {false};
     int current_sector = 1;
     
     int gamer_score = 0;
     int viewers_score = 0;

     while (gamer_score < 6 && viewers_score < 6){
        choice_sector(game_sectors, current_sector);
        if (get_question_check_answer(current_sector)){
            ++gamer_score;
        }
        else {
            ++viewers_score;
        }
        cout << "����:" << endl << "�������� - " << gamer_score << endl << "����������� - " << viewers_score << endl;
     }

     if (gamer_score == 6){
        cout << "�������� �������";
     }
     else {
        cout << "�������� �����������";
     }
}