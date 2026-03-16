#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define ATTR1 30
#define ATTR2 63
using namespace std;

CONSOLE_SCREEN_BUFFER_INFO csbuf;           // змінна, яка міститиме інформацію про буфер
const char* m[] = { "FIRST MODE", "SECOND  MODE", "HELP", "ABOUT CREATOR", "EXIT" };

void bottomtext(HANDLE h, string phrase){
	int consoleWidth = csbuf.srWindow.Right - csbuf.srWindow.Left + 1; //120
    int consoleHeight = csbuf.srWindow.Bottom - csbuf.srWindow.Top + 1; //30
    int startX = (consoleWidth - phrase.length() + 4) / 2; 
    int startY = (consoleHeight - 3) / 2 + 14; 
    SetConsoleCursorPosition(h, {startX, startY});
    cout << phrase;
}
void draw_bond(HANDLE h, COORD t, COORD b) {
    int lenx = b.X - t.X - 2;  // розмір таблиці по x
    int leny = b.Y - t.Y - 1;  // розмір таблиці по y
	COORD f = t;
    unsigned char c;                                 // далі використовуємо символи псевдографіки. Unicode таблиця символів
    SetConsoleCursorPosition(h, f);
    c = 457; cout << c;                              // подвійний лівий верхній кут
    f.X++; c = 461;                                  // подвійний горизонтальний
    for (int i = 0; i < lenx; i++) cout << c; 
    c = 443; cout << c << endl;                      // подвійний правий верхній кут
    c = 442; f = t;                                  // подвійний вертикальний
    f.Y++;
    for (int i = 0; i < leny; i++) {
        SetConsoleCursorPosition(h, f); 
        f.Y++; cout << c;
	}
    c = 456;                                         // подвійний лівий нижній кут
    SetConsoleCursorPosition(h, f); 
    cout << c;
    f = b;
    c = 442;                                         
    SetConsoleCursorPosition(h, f); 
    f.Y--; f.X--;
    for (int i = 0; i < leny; i++) {
        SetConsoleCursorPosition(h, f); 
        f.Y--;
        cout << c;
    }
    f = t;
    f.Y += leny + 1; 
    SetConsoleCursorPosition(h, f);
    c = 456; cout << c;
    f.X++;
    c = 461;
    for (int i = 0; i < lenx; i++) {
        cout << c;
    }
    c = 444; cout << c << endl;
    c = 196;                                         // одинарний горизонтальний
    f = t;
    f.Y = f.Y + 2; f.X = f.X + 1;
    for (int i = 0; i < lenx; i++) {
        SetConsoleCursorPosition(h, f); 
        f.X++;
        cout << c;
	}  
    for (int k = 0; k < 6; k++) {
    c = 196;
    f.Y = f.Y + 2; f.X = f.X - lenx;
    for (int i = 0; i < lenx; i++) {
        SetConsoleCursorPosition(h, f); 
        f.X++;
        cout << c;
    }
	}
    c = 179;                                         // одинарний вертикальний
    f = t;
    f.Y = f.Y + 1; f.X = f.X + 8;
    for (int i = 0; i < leny; i++) {
        SetConsoleCursorPosition(h, f); 
        f.Y++;
        cout << c;
    } 
    f.X = f.X + 17; f.Y = f.Y - leny;
    for (int i = 0; i < leny; i++) {
        SetConsoleCursorPosition(h, f); 
        f.Y++;
        cout << c;
    } 
    f.X = f.X + 7; f.Y = f.Y - leny;
    for (int i = 0; i < leny; i++) {
        SetConsoleCursorPosition(h, f); 
        f.Y++;
        cout << c;
    } 
    f = t;
    f.Y = f.Y + 1.5; f.X = f.X + 3;
    SetConsoleCursorPosition(h, f); 
    cout << "Try";
    f.X = f.X + 11;
    SetConsoleCursorPosition(h, f); 
    cout << "Number";
    f.X = f.X + 13;
    SetConsoleCursorPosition(h, f); 
    cout << "Bull";
    f.X = f.X + 7;
    SetConsoleCursorPosition(h, f); 
    cout << "Cow";
}
void drawtabl(HANDLE h){
    int consoleWidth = csbuf.srWindow.Right - csbuf.srWindow.Left + 1; 
    int consoleHeight = csbuf.srWindow.Bottom - csbuf.srWindow.Top + 1;
    string phrase1 = "BULLS AND COWS";
    string phrase3 = "Your goal: guess the number in less than 15 steps";
    int startX1 = (consoleWidth - phrase1.length()) / 2; 
    int startY1 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX1, startY1 - 11});
    cout << phrase1 << endl;
    string phrase2 = "FIRST MODE";
    int startX2 = (consoleWidth - phrase2.length()) / 2; 
    int startY2 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX2, startY2 - 9});
    cout << phrase2 << endl;
    int startX3 = (consoleWidth - phrase3.length()) / 2; 
    int startY3 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX3, startY3 - 7});
    cout << phrase3 << endl;
    COORD top = {15, 9}; 
    COORD bottom = {55, 25}; 
    draw_bond(h, top, bottom);
    top = {65, 9}; 
    bottom = {105, 25}; 
    draw_bond(h, top, bottom);
}
void drawtabl1(HANDLE h){
    int consoleWidth = csbuf.srWindow.Right - csbuf.srWindow.Left + 1;  // розміри вікна із параметра srWindow буфера консолі
    int consoleHeight = csbuf.srWindow.Bottom - csbuf.srWindow.Top + 1;
    string phrase1 = "BULLS AND COWS";
    string phrase3 = "Your goal: make your computer guess your number in less than 29 steps";
    int startX1 = (consoleWidth - phrase1.length()) / 2; 
    int startY1 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX1, startY1 - 11});
    cout << phrase1 << endl;
	string phrase2 = "SECOND MODE";
    int startX2 = (consoleWidth - phrase2.length()) / 2; 
    int startY2 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX2, startY2 - 9});
    cout << phrase2 << endl;
    int startX3 = (consoleWidth - phrase3.length()) / 2; 
    int startY3 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX3, startY3 - 7});
    cout << phrase3 << endl;
    COORD top = {15, 9};           // таблиця 1
    COORD bottom = {55, 25};       
    draw_bond(h, top, bottom);
    top = {65, 9};                 // таблиця 2
    bottom = {105, 25}; 
    draw_bond(h, top, bottom);
    
}
void helpk15(HANDLE h, COORD t, COORD b, int k){
    COORD f;
    if (k > 14 && k < 22){ f = {15, 10}; } 
	if (k > 21 && k < 29){ f = {65, 10}; f.Y = f.Y - 14;} 
    k = k - 14;
	f.X = f.X + 4; f.Y = f.Y + 2 * k;
    SetConsoleCursorPosition(h, f); 
    k = k + 14;
    cout << 1 * k;
    f.X = f.X + 11;
    SetConsoleCursorPosition(h, f); 
}
void setpos(HANDLE h, COORD t, COORD b, int k) {
    COORD f;
    if (k < 8){ f = {15, 10};} 
	if (k > 7 && k < 15){ f = {65, 10}; f.Y = f.Y - 14; } 
    if (k == 15) { system("cls"); drawtabl1(h);  f = {15, 10}; helpk15(h, t, b, k); return; }
    if (k > 15 && k < 22){ f = {15, 10}; helpk15(h, t, b, k); return; } 
	if (k > 21 && k < 29){ f = {65, 10}; f.Y = f.Y - 14; helpk15(h, t, b, k); return; } 
    f.X = f.X + 4; f.Y = f.Y + 2 * k;
    SetConsoleCursorPosition(h, f); 
    cout << 1 * k;
    f.X = f.X + 11;
    SetConsoleCursorPosition(h, f); 
    }
void drawbc(HANDLE h, COORD t, COORD b, int bull, int cow, int k) {
    COORD f;
    if (k < 8){ f = {15, 10};} else{ f = {65, 10}; f.Y = f.Y - 14; }
    f.X = f.X + 29; f.Y = f.Y + 2 * k;
    SetConsoleCursorPosition(h, f); 
    cout << bull << " "; 
	f.X = f.X + 7;
    SetConsoleCursorPosition(h, f); 
	cout << cow - bull; 
}
int drawb(HANDLE h, COORD t, COORD b, int bulls, int cows, int k) {
    COORD f;
    if (k < 8){ f = {15, 10}; f.X = f.X + 29; f.Y = f.Y + 2 * k;} 
	if (k > 7 && k < 15){ f = {65, 10}; f.Y = f.Y - 14;  f.X = f.X + 29; f.Y = f.Y + 2 * k;} 
    if (k == 15) { f = {15, 10}; f.X = f.X + 29; k = k - 14; f.Y = f.Y + 2 * k;  k = k + 14;}
    if (k > 15 && k < 22){ f = {15, 10}; f.X = f.X + 29; k = k - 14; f.Y = f.Y + 2 * k;  k = k + 14;} 
	if (k > 21 && k < 29){ f = {65, 10}; f.X = f.X + 29; f.Y = f.Y - 14; k = k - 14; f.Y = f.Y + 2 * k;  k = k + 14; } 
    SetConsoleCursorPosition(h, f); 
    cin >> bulls; 
	return bulls; }
int drawc(HANDLE h, COORD t, COORD b, int bulls, int cows, int k) {
    COORD f;
    if (k < 8){ f = {15, 10}; f.X = f.X + 29; f.Y = f.Y + 2 * k; f.X = f.X + 7;} 
	if (k > 7 && k < 15){ f = {65, 10}; f.Y = f.Y - 14; f.X = f.X + 29; f.Y = f.Y + 2 * k; f.X = f.X + 7;} 
    if (k == 15) { f = {15, 10}; f.X = f.X + 29; k = k - 14; f.Y = f.Y + 2 * k; f.X = f.X + 7; k = k + 14;}
    if (k > 15 && k < 22){ f = {15, 10}; k = k - 14; f.X = f.X + 29; f.Y = f.Y + 2 * k; f.X = f.X + 7; k = k + 14;} 
	if (k > 21 && k < 29){ f = {65, 10}; f.Y = f.Y - 14; k = k - 14; f.X = f.X + 29; f.Y = f.Y + 2 * k; f.X = f.X + 7;k = k + 14;} 
    SetConsoleCursorPosition(h, f); 
	cin >> cows;
	return cows;}
int Mode1(HANDLE h, int r){
	drawtabl(h);
    COORD top = {65, 9}; 
    COORD bottom = {105, 25}; 
	int a, b, ran[4], i, j, c[4], bull, cow;
    int k = 1;
	bool f = 0;
	while (true){
	    i = 0; 
	    srand(time(NULL));
	    while(i < 4){
			ran[i] = rand() % 10;           // генерація числа від 0 до 9
			for (j = 0; j < i; j++){
				if (ran[i] == ran[j]) {     // перевірка чи не повторюються цифри
					f = 1;                  // перевірка - вихід
					break;
				}
			}
			if (f == 0) {                   // не повторюються - наступна перевірка
				i++;
			}
			f = 0;
		}
		int s = 0;
		while (true) {	
		    bull = 0;
		    cow = 0;
            setpos(h, top, bottom, k);
			cin >> a;
			string phrase101 = "                                                ";
			bottomtext(h, phrase101);
			int digits[10] = {0};
            int temp = a;
            int temp1 = a;
            int y = 0;
            int t = 1;
            int kom = 0;
            while (t < 5) {                                    // перевірка на повтори числа користувача
                int digit = temp % 10;                         // digit - остача від ділення на 10
		        digits[digit]++;                               
                temp /= 10;  
                t++;
            }   
            bool hasError = false;
            for (int i = 0; i < 10; i++) {
                if (digits[i] > 1) {
        	        setpos(h, top, bottom, k);
                    cout << "     ";
                    setpos(h, top, bottom, k);
                    string phrase102 = "Error. Digits are repeated in your number.";
                    bottomtext(h, phrase102);
                    hasError = true;
                    break;
                }
            }
			if (hasError) { continue; }
			for (i = 3; i >= 0; i--) {
				b = a % 10;
				c[i] = b;
				a = (a - b) / 10;
			}
			for (i = 0; i < 4; i++) {
				if (c[i] == ran[i]) {
					bull++;
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (c[i] == ran[j]) {
						cow++;
					}
				}
			}
            drawbc(h, top, bottom, bull, cow, k);
            k++;
		    if (bull == 4) {
				string phrase4 = "You won! Another try? 1(yes) or 0(no):  ";
                bottomtext(h, phrase4);
                int answer1; cin >> answer1;
				system("cls");
			    if (answer1 == 1) { return 1; } else if (answer1 == 0) { return 0; }
		    }
	        if (k == 15){	
	            string phrase5 = "You lost. Another try? 1(yes) or 0(no):  ";
                bottomtext(h, phrase5);
                int answer2; cin >> answer2;
			    system("cls");
			    if (answer2 == 1) { return 1; } else if (answer2 == 0) { return 0; }
			}
		}
		f = 0;  }
		}
int b2c2(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[6][4] = { {currentun[0], currentun[1], currentun[3], currentun[2]},
        {currentun[0], currentun[3], currentun[2], currentun[1]},
        {currentun[0], currentun[2], currentun[1], currentun[3]},
        {currentun[3], currentun[1], currentun[2], currentun[0]},
        {currentun[2], currentun[1], currentun[0], currentun[3]},
        {currentun[1], currentun[0], currentun[2], currentun[3]}};
    for (int i = 0; i < 6; ++i) {
    	setpos(hConsole, top, bottom, k);
    	for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;    
        if ( k > 28 ) { return k; }
		if (bulls == 4) { return k;}                                     
} k = k + 30; return k;
}
int b1c3(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[8][4] = {{currentun[0], currentun[3], currentun[1], currentun[2]},
        {currentun[0], currentun[2], currentun[3], currentun[1]},
        {currentun[3], currentun[1], currentun[0], currentun[2]},
        {currentun[2], currentun[1], currentun[3], currentun[0]},
        {currentun[3], currentun[0], currentun[2], currentun[1]},
        {currentun[1], currentun[3], currentun[2], currentun[0]},
        {currentun[2], currentun[0], currentun[1], currentun[3]},
        {currentun[1], currentun[2], currentun[0], currentun[3]}};
    for (int i = 0; i < 8; ++i) {
    	setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;  
			if ( k > 28 ) { return k; }   
        if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
        if (bulls == 4) { return k;}
    } k = k + 30; return k;
}
int b0c4(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[9][4] = {{currentun[1], currentun[0], currentun[3], currentun[2]},
        {currentun[1], currentun[3], currentun[0], currentun[2]},
        {currentun[1], currentun[2], currentun[3], currentun[0]},
        {currentun[2], currentun[0], currentun[3], currentun[1]},
        {currentun[2], currentun[3], currentun[1], currentun[0]},
        {currentun[2], currentun[3], currentun[0], currentun[1]},
        {currentun[3], currentun[0], currentun[1], currentun[2]},
        {currentun[3], currentun[2], currentun[0], currentun[1]},
        {currentun[3], currentun[2], currentun[1], currentun[0]},};
    for (int i = 0; i < 9; ++i) {
    	setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
        if (bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k);return k;}
        if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
        if (bulls == 4) {return k;}
    } k = k + 30; return k;
}
int b3c0(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[24][4];
    int permutationIndex = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[1];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[2];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;}
    }
    for (int i = 0; i < 24; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j]; }
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
        if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
        if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
        if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
        if (bulls == 4) {return k;}
    } k = k + 30; return k;
}
int b2c1(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for(int i = 0; i < 2; ++i){
    	for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[1];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[0];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[2];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;} 
    }
    for(int i = 0; i < 3; i = i + 2){
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[2];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[1];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[0];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;
			}
			}
    for(int i = 0; i < 4; i = i + 3){
    	for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[3];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[1];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[2];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[0];
			permutationIndex++;
	}
}
	for(int i = 1; i < 3; ++i){
    	for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[2];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[1];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;}
	}
    for (int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
    } 
}
int b2c0(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue; 
		int i = 3;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[1];
            permutations[permutationIndex][2] = (i == 2) ? j : f;
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;}
	}
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue; int i = 3;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[2];
            permutations[permutationIndex][1] = (i == 1) ? j : f;
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;}
	}
	for(int i = 0; i < 30; ++i) {
		setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
	}
}
int b1c2(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for(int i = 0; i < 4; i = i + 3){
    		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[2];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[1];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[3];
			permutationIndex++;}
	}
	for(int i = 0; i < 3; i = i + 2){
		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[3];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[2];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[1];
			permutationIndex++;}
	}
	for(int i = 0; i < 2; ++i){
		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[0];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[1];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[3];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[2];
			permutationIndex++;}
	}
	for(int i = 0; i < 30; ++i) {
	    setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
    }
}
int b0c3(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for(int i = 0; i < 4; ++i){
    		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[1];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[0];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[3];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[2];
			permutationIndex++;}
	}
	for(int i = 0; i < 4; ++i){
    		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[3];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[0];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[1];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[2];
			permutationIndex++;}
	}
	for(int i = 0; i < 4; ++i){
    		for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3]) continue;
            permutations[permutationIndex][0] = (i == 0) ? j : currentun[2];
            permutations[permutationIndex][1] = (i == 1) ? j : currentun[0];
            permutations[permutationIndex][2] = (i == 2) ? j : currentun[3];
            permutations[permutationIndex][3] = (i == 3) ? j : currentun[1];
			permutationIndex++;}
	}
		for (int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k; }
	}
}
int b0c0(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int m = 0; m <= 9; ++m) {
    if (m == currentun[0] || m == currentun[1] || m == currentun[2] || m == currentun[3]) continue;
	for (int k = 0; k <= 9; ++k) {
    if (k == currentun[0] || k == currentun[1] || k == currentun[2] || k == currentun[3] || k == m) continue;
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3] || f == k || f == m) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f || j == k || j == m) continue;
            permutations[permutationIndex][0] = m;
            permutations[permutationIndex][1] = k;
            permutations[permutationIndex][2] = f;
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
			}
    } 
    for(int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 3){ k = b0c3(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
	}
	}
int b1c0(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int k = 0; k <= 9; ++k) {
    if (k == currentun[0] || k == currentun[1] || k == currentun[2] || k == currentun[3]) continue;
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3] || f == k) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f || j == k ) continue;
            permutations[permutationIndex][0] = currentun[0];
            permutations[permutationIndex][1] = k;
            permutations[permutationIndex][2] = f;
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
    }
	for(int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++; 
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 3){ k = b0c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 0){ k = b0c0(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;
	}
    } 
}
int b1c1(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[0];
            permutations[permutationIndex][1] = currentun[2];
            permutations[permutationIndex][2] = f;
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[0];
            permutations[permutationIndex][1] = currentun[3];
            permutations[permutationIndex][2] = f;
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[0];
            permutations[permutationIndex][1] = f;
            permutations[permutationIndex][2] = currentun[1];
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
			for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[0];
            permutations[permutationIndex][1] = f;
            permutations[permutationIndex][2] = currentun[3];
            permutations[permutationIndex][3] = j;
			permutationIndex++;}
			}
	for(int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 3){ k = b0c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 0){ k = b0c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 0){ k = b1c0(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
	}
	}
int b0c2(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[1];
            permutations[permutationIndex][1] = currentun[0];
            permutations[permutationIndex][2] = f;
            permutations[permutationIndex][3] = j;
            permutationIndex++;
        }
	}
	for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[2];
            permutations[permutationIndex][1] = f;
            permutations[permutationIndex][2] = currentun[0];
            permutations[permutationIndex][3] = j;
            permutationIndex++;
        }
	}
	for (int f = 0; f <= 9; ++f) {
        if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3]) continue;
        for (int j = 0; j <= 9; ++j) {
            if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f) continue;
            permutations[permutationIndex][0] = currentun[3];
            permutations[permutationIndex][1] = f;
            permutations[permutationIndex][2] = j;
            permutations[permutationIndex][3] = currentun[0];
            permutationIndex++;
        }
	}
    for(int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 3){ k = b0c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 0){ k = b0c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 0){ k = b1c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 1){ k = b1c1(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k;}
	}
}
int b0c1(int currentun[], HANDLE hConsole, COORD top, COORD bottom, int k) {
    int permutations[120][4];
    int permutationIndex = 0;
    for (int w = 0; w <= 9; ++w) {
        if (w == currentun[0] || w == currentun[1] || w == currentun[2] || w == currentun[3]) { continue; }
        for (int f = 0; f <= 9; ++f) {
            if (f == currentun[0] || f == currentun[1] || f == currentun[2] || f == currentun[3] || f == w) { continue; }
            for (int j = 0; j <= 9; ++j) {
                if (j == currentun[0] || j == currentun[1] || j == currentun[2] || j == currentun[3] || j == f || j == w ) { continue; }
                permutations[permutationIndex][0] = currentun[1];
                permutations[permutationIndex][1] = w;
                permutations[permutationIndex][2] = f;
                permutations[permutationIndex][3] = j;
			    permutationIndex++;}
	}
    }
    for(int i = 0; i < 30; ++i) {
        setpos(hConsole, top, bottom, k);
        for (int j = 0; j < 4; ++j) { cout << permutations[i][j];}
        int bulls, cows;                                       
        bulls = drawb(hConsole, top, bottom, bulls, cows, k);
        cows = drawc(hConsole, top, bottom, bulls, cows, k);
        k++;
        	if ( k > 28 ) { return k; }
    if (bulls == 2 && cows == 2){ k = b2c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 3){ k = b1c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 4){ k = b0c4(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 3 && cows == 0){ k = b3c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 1){ k = b2c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 2 && cows == 0){ k = b2c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 2){ k = b1c2(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 3){ k = b0c3(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 0){ k = b0c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 0){ k = b1c0(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 1 && cows == 1){ k = b1c1(permutations[i], hConsole, top, bottom, k); return k;}
    if(bulls == 0 && cows == 2){ k = b0c2(permutations[i], hConsole, top, bottom, k); return k;}
    if (bulls == 4) { return k; }
	}
}
int Mode2(HANDLE h, int r){
    int consoleWidth = csbuf.srWindow.Right - csbuf.srWindow.Left + 1; //120
    int consoleHeight = csbuf.srWindow.Bottom - csbuf.srWindow.Top + 1; //30
    COORD top = {65, 9}; 
    COORD bottom = {105, 25};
    string phrase6 = "Please, come up with a four-digit number for the next game.";
	int startX6 = (consoleWidth - phrase6.length() + 4) / 2; 
    int startY6 = (consoleHeight - 3) / 2 - 1; 
    SetConsoleCursorPosition(h, {startX6, startY6});
    cout << phrase6;
    string phrase7 = "Say yes when you are ready :)   ";
	int startX7 = (consoleWidth - phrase7.length() + 4) / 2; 
    int startY7 = (consoleHeight - 3) / 2; 
    SetConsoleCursorPosition(h, {startX7, startY7});
    cout << phrase7;
    string answer100; cin >> answer100;
    system("cls");
    drawtabl1(h); 
	int a, b, ran[4], i, j, c[4], bull, cow, m;
    int k = 1;
    int currentun[4] = {0}; 
    int bulls, cows;
    int ans = 1;
    bool f = 0; i = 0;
        srand(time(NULL));
	    while(i < 4){
			ran[i] = rand() % 10;
			for (j = 0; j < i; j++){
				if (ran[i] == ran[j]) {
					f = 1;
					break;
				}
			}
			if (f == 0) {
				i++;
			}
			f = 0;
		}
        setpos(h, top, bottom, k);
        for (int i = 0; i < 4; ++i) {
            currentun[i] = ran[i];
            cout << currentun[i];
        }
        bulls = drawb(h, top, bottom, bulls, cows, k);	
        cows = drawc(h, top, bottom, bulls, cows, k); 
        k++;
        if (bulls == 2 && cows == 2) { k = b2c2(currentun, h, top, bottom, k);} //right 6
        else if (bulls == 1 && cows == 3) { k = b1c3(currentun, h, top, bottom, k);} //right 8
        else if (bulls == 0 && cows == 4) { k = b0c4(currentun, h, top, bottom, k);} //right 9
        else if (bulls == 3 && cows == 0) { k = b3c0(currentun, h, top, bottom, k);} //right 24
        else if (bulls == 2 && cows == 1) { k = b2c1(currentun, h, top, bottom, k);} //right 72
        else if (bulls == 1 && cows == 2) { k = b1c2(currentun, h, top, bottom, k);} //right 216
        else if (bulls == 0 && cows == 3) { k = b0c3(currentun, h, top, bottom, k);} //right 264
        else if (bulls == 2 && cows == 0) { k = b2c0(currentun, h, top, bottom, k);} //right 180
        else if (bulls == 1 && cows == 1) { k = b1c1(currentun, h, top, bottom, k);} //right 720
        else if (bulls == 0 && cows == 2) { k = b0c2(currentun, h, top, bottom, k);} //right 1260
        else if (bulls == 1 && cows == 0) { k = b1c0(currentun, h, top, bottom, k);} //right 480
        else if (bulls == 0 && cows == 1) { k = b0c1(currentun, h, top, bottom, k);} //right 1440
        else if (bulls == 0 && cows == 0) { k = b0c0(currentun, h, top, bottom, k);} //right 360
        if (k == 29) {
		string phrase5 = "You lost. Another try? 1(yes) or 0(no):  ";
                bottomtext(h, phrase5);
                int answer; cin >> answer;
				system("cls");
			    if (answer == 1) { return 1; } else if (answer == 0) { return 0; }
			}
			if (k > 29) {
		string phrase6 = "You made a mistake somewhere and game connot be continued. Another try? 1(yes) or 0(no):  ";
                bottomtext(h, phrase6);
                int answer; cin >> answer;
				system("cls");
			    if (answer == 1) { return 1; } else if (answer == 0) { return 0; }
			}
		string phrase8 = "You won! Another try? 1(yes) or 0(no):  ";
                bottomtext(h, phrase8);
                int answer1; cin >> answer1;
				system("cls");
			    if (answer1 == 1) { return 1; } else if (answer1 == 0) { return 0; }
				}
int FIRSTMODE(HANDLE h) {
    system("cls");
    int r = 1;
    do{
    	r = Mode1(h, r);	
	} while (r == 1);
	system("cls");
            return 0;}
int SECONDMODE(HANDLE h) {
    system("cls");
    int r = 1;
    do{
    	r = Mode2(h, r);	
	} while (r == 1);
    system("cls");
	return 0;}
void help(HANDLE h, COORD c, COORD b) {
	system("cls");
    SetConsoleCursorPosition(h, c);
    cout << "HELP" << endl;
    b.Y--; SetConsoleCursorPosition(h, b);
    cout << "Bulls and Cows is a classic puzzle game. Our program offers you two modes of this game. " << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You can read detailed instruction next:" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "FIRST MODE:" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "The rules are simple: The computer guesses a four-digit number, for example 1234 (digits can't be repeated)." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You have to try to guess that number." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "After each attempt, the computer tells you how many numbers you guessed: " << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "how many of them are in the right places - bulls," << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "and how many of them are in the number but not in the right places - cows." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "If the assigned number is 1234 and you tried 1243," << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "it means that you guessed two bulls (1 and 2) and two cows (4 and 3)." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You lost if you have not guessed number in 14 tries, and won if you have. " << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "SECOND MODE:" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You guess a four-digit number, for example 1234 (digits cannot be repeated)." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You together with computer have to try to guess your number." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "After each computer's attempt to guess your number, you have to say how many digits of the number computer guessed: " << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "how many of them are in the right places - bulls," << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "and how many of them are in the number but not in the right places - cows." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "If the assigned number is 1234 and computer tried 1243," << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "it means that computer guessed two bulls (1 and 2) and two cows (4 and 3)." << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "You lost if computer have not guessed number in 28 tries, and won if computer have. " << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "Good luck!" << endl;
    system("pause");
    }
void about(HANDLE h, COORD c, COORD b) {
	system("cls");
    SetConsoleCursorPosition(h, c);
    cout << "ABOUT CREATOR" << endl;
    SetConsoleCursorPosition(h, b);
    cout << "Creator: Bardyk Diana from KA-32" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout<<"If you have any questions or suggestions, you can write to me using the contacts below:" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "Mobile phone: +380508712085" << endl;
    b.Y++; SetConsoleCursorPosition(h, b);
    cout << "Mail: bardyk.diana@lll.kpi.ua" << endl;
    system("pause");
    }
void drawMenu(HANDLE h, COORD c, int k, int n) {
    SetConsoleTextAttribute(h, ATTR1);
    COORD cc = c;

    cc.X = c.X - strlen("BULLS AND COWS") / 2 + 20;
    cc.Y = c.Y - 4;
    SetConsoleCursorPosition(h, cc);
    cout << "BULLS AND COWS" << endl;

    for (int i = 0; i < n; i++) {
        cc.Y = c.Y + i * 2;
        cc.X = c.X - strlen(m[i]) / 2 + 20;
        SetConsoleCursorPosition(h, cc);
        cout << m[i];    }

    cc.Y = c.Y + k * 2;
    SetConsoleTextAttribute(h, ATTR2);
    cc.X = c.X - strlen(m[k]) / 2 + 20;
    SetConsoleCursorPosition(h, cc);
    cout << m[k];}
int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);         // отриматуємо дескриптор консольного вікна
    GetConsoleScreenBufferInfo(h, &csbuf);              // отримуємо інформацію про буфер екрана консолі
    SetConsoleTextAttribute(h, BACKGROUND_BLUE );
    system("cls");
    COORD bufferSize = { 80, 70 };
    SetConsoleScreenBufferSize(h, bufferSize);
    COORD start = { 40 , 10 }, info = {50, 2}, text = { 3, 5 };      // початок меню, початок тексту в пунктах (заголовку та тексту)
    int n = 5;    // кількість пунктів меню
    int option = 0;

    drawMenu(h, start, option, n);

    while (true) {
        char key = _getch();  // зчитує символ
        switch (key) {
        case 27:              // esc
            key = 0;
            system("cls");
            return 0;

        case 13:
            switch (option) {
            case 0: FIRSTMODE(h); SetConsoleTextAttribute(h, BACKGROUND_BLUE );
    system("cls"); break;
            case 1: SECONDMODE(h); SetConsoleTextAttribute(h, BACKGROUND_BLUE );
    system("cls"); break;
            case 2: help(h, info, text); SetConsoleTextAttribute(h, BACKGROUND_BLUE );
    system("cls"); break;
            case 3: about(h, info, text); SetConsoleTextAttribute(h, BACKGROUND_BLUE );
    system("cls"); break;
            case 4: system("cls"); return 0;}
            system("cls"); drawMenu(h, start, option, n); break;
            case KEY_ARROW_DOWN: // down
            if (option == n - 1) { option = 0; }
            else { option++; }
            drawMenu(h, start, option, n); break;

        case KEY_ARROW_UP: // up
            if (option == 0){ option = n - 1; }
            else { option--; }
            drawMenu(h, start, option, n); break;
        }
    }

    return 0;
}