/*
Задание 5. Реализация игры «Что? Где? Когда?»
Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».
Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий не игравший за ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора. Вопрос показывается на экране.
После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.
Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и программа заканчивает работу.

Что оценивается
Игра должна корректно работать от первого хода до последнего. В результате обязательно должен выявляться победитель.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void choice_sector(bool game_sector[13], int& current_sector){
    cout << "Введите смещение сектора: ";
    int shift;
    cin >> shift;
    current_sector = (current_sector + shift) % 13;
    while (game_sector[current_sector-1]){
        current_sector = (current_sector +1) % 13;
    }
    game_sector[current_sector-1] = true;
    cout << "Сектор № " << current_sector << endl;
}

bool get_question_check_answer(const int& current_sector){
    string questions[13] = {"question1.txt", "question2.txt","question3.txt","question4.txt","question5.txt",
                            "question6.txt","question7.txt","question8.txt","question9.txt","question10.txt",
                            "question11.txt","question12.txt","question13.txt"};

    ifstream question_file;
    question_file.open(questions[current_sector-1]);
    cout << "Вопрос: ";

    while (!question_file.eof()){
        char buffer[20];
        question_file.read(buffer, sizeof(buffer));
        for (int i=0; i<question_file.gcount(); ++i){
            cout << buffer[i];
        }
    }
    cout << endl;

    question_file.close();

    cout << "Введите ответ на вопрос: ";
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
        cout << "Ответ верный" << endl;
        return true;
    }
    cout << "Ответ неверный" << endl;
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
        cout << "Счет:" << endl << "Знатоки - " << gamer_score << endl << "Телезрители - " << viewers_score << endl;
     }

     if (gamer_score == 6){
        cout << "Победили знатоки";
     }
     else {
        cout << "Победили телезрители";
        
     }
}