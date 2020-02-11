#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "User_interface.h"
#include "Main_Functions.h"
using namespace std;

int score = 0;

void menu_logo() 
{
	cout << "\n\n\n\n\n\n\n";
	char logo1[50]{ "\t\t\t\t\t ____  __ _   __ __  __  ____" };
	char logo2[50]{ "\t\t\t\t\t/ ___)(  ( \\ / _\\\\ \\/ / (  __)" };
	char logo3[50]{ "\t\t\t\t\t\\___ \\/    //    \\\\   \\  ) _)" };
	char logo4[50]{ "\t\t\t\t\t(____/\\_)__)\\_/\\_/|_|\\_)(____)" };

	cout << logo1 << endl;
	Sleep(150);
	cout << logo2 << endl;
	Sleep(150);
	cout << logo3 << endl;
	Sleep(150);
	cout << logo4 << endl;
	Sleep(150);
}

void menu_StartScreen(int switcher)
{
	system("cls");
	switch (switcher)
	{
	case 1:

		cout << "\t\t\t\t==============================================="
			<< "\n\t\t\t\t||\t***WELCOME TO SNAKE CONSOLE!***\t     ||"
			<<"\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t   ->\t    Start \t<-\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t\t Instructions \t\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t\t     Quit\t\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||\n"			
			<< "\t\t\t\t===============================================\n\n"
			<< "\n\nPrevios Player Info:\n"
			<< "**********************\n"
			<< "Name:\t\tScore:\n\n";
		openScoreFile();
		cout << "**********************\n";
		break;

	case 2:

		cout << "\t\t\t\t==============================================="
			<< "\n\t\t\t\t||\t***WELCOME TO SNAKE CONSOLE!***\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t     \t    Start \t  \t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t->\t Instructions \t     <-\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t\t     Quit\t\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||\n"
			<< "\t\t\t\t===============================================\n\n"
			<< "\n\nPrevios Player Info:\n"
			<< "**********************\n"
			<< "Name:\t\tScore:\n\n";
			openScoreFile();
		cout << "**********************\n";
		break;

	case 3:

		cout << "\t\t\t\t==============================================="
			<< "\n\t\t\t\t||\t***WELCOME TO SNAKE CONSOLE!***\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t     \t    Start \t  \t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t\t Instructions \t\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||"
			<< "\n\t\t\t\t||\t   ->\t     Quit\t<-\t     ||"
			<< "\n\t\t\t\t||\t\t\t\t\t     ||\n"
			<< "\t\t\t\t===============================================\n\n"
			<< "\n\nPrevios Player Info:\n"
			<< "**********************\n"
			<< "Name:\t\tScore:\n\n";
		openScoreFile();
		cout << "**********************\n";
		break;

	default:
		break;
	}

	switchStartScreen(switcher);
}

void menu_Instructions()
{
	system("cls");
	cout << "\t\t       ___\n"
		"\t\t     ,-----,\t\tUse the 'W' key to go UP.\n"
		"\t\t    /\\|   |/\\ \t\tUse the 'A' key to turn LEFT.\n"
		"\t\t   |-- \\_/ --|\t\tUse the 'S' key to go DOWN.\n"
		"\t\t .-----/ \\-----.\tUse the 'D' key to turn RIGHT.\n"
		"\t\t/  ,   . .   ,  \\ \tDO NOT eat your own tail or you will LOSE!\n"
		"\t       / /'|    |    |'\\,\\ \tNow press the \"Enter\" button to go MENU.\n"
		"\t       `\\ \\ \\-  |  -/ /`/' \n"
		"\t        `\\\\_)`-- --'(_// \n"
		"\t          |_|`-- --'|_|  _______ \n"
		"\t           ,'`-   -'`.,-'       `-. \n"
		"\t          |\\--------/||            `-.      _,------. \n"
		"\t         |\\---------/`|    .--.       `----'   ___--.`--. \n"
		"\t          |\\---------/\\. .\"    `.            ,'      `---' \n"
		"\t           ``-._______.-'        `-._______.-' \n";
	
	int choice = _getch();
	if (choice == 13 || choice == 32)
		menu_StartScreen(1);	
}

void menu_level(int switcher) 
{
	system("cls");
	switch (switcher)
	{
	case 1: 
		
		cout << "\n\n\t\t\t\t\t\tChoose level to play\n\n"
			<< "     --..,_                    _,.--.\t\t->\tBaby\t<-\n"
			<< "\t`'.'.                .'`__ o  `;__.\t\tAggressive\n"
			<< "\t   '.'.            .'.'`  '---'`  '\t\tSnake charmer\n"
			<< "\t     '.`'--....--'`.'\n"
			<< "\t       `'--....--'`";
		break;

	case 2:
		
		cout << "\n\n\t\t\t\t\t\tChoose level to play\t\n\n"
			<< "\t ---_ ......._-_--.\t\t\t\tBaby\n"
			<< "\t(|\\ /      / /| \\  \\\t\t\t->\tAggressive\t<-\n"
			<< "\t/  /     .'  -=-'   `.\t\t\t\tSnake charmer\n"
			<< "       /  /    .'            )\n"
			"     _/  /   .'        _.)  /\n"
			"    / o   o        _.-' /  .'\n"
			"    \\         _.-'     / .'*|\n"
			"     \\______.-'//    .'.' \\*|\n"
			"      \\|  \\ | //   .'.' _ |*|\n"
			"       `   \\|//  .'.'_ _ _|*|\n"
			"        .  .// .'.' | _ _ \\*|\n"
			"        \\`-|\\_/ /    \\ _ _ \\*\\\n"
			"         `/'\\__/      \\ _ _ \\*\\\n"
			"         /^|           \\ _ _ \\*\n"
			"        '  `            \\ _ _ \\ \n"
			"	                 \\_";
		break;

	case 3:
		
		cout << "\n\n\t\t\t\t\t\tChoose level to play\t\n\n"
			<< "\t___\t\t\t\t\t\tBaby\n"
			<< "      ,'._,`.\t\t\t\t\t\tAggressive\n"
			<< "     (-.___.-)\t\t\t\t\t->\tSnake charmer\t<-\n"
			"     (-.___.-)\n"
			"     `-.___.-' \n"
			"      ((  @ @|              .            __\n"
			"       \\   ` |         ,\\   |`.    @|   |  |      _.-._\n"
			"      __`.`=-=mm===mm:: |   | |`.   |   |  |    ,'=` '=`.\n"
			"     (    `-'|:/  /:/  `/  @| | |   |, @| @|   /---)W(---\\\n"
			"      \\ \\   / /  / /         @| |   '         (----| |----) ,~\n"
			"      |\\ \\ / /| / /            @|              \\---| |---/  |\n"
			"      | \\ V /||/ /                              `.-| |-,'   |\n"
			"      |  `-' |V /                                 \\| |/    @'\n"
			"      |    , |-'                                 __| |__\n"
			"      |    .;: _,-.                         ,--\"\"..| |..\"\"--.\n"
			"      ;;:::' \"    )                        (`--::__|_|__::--')\n"
			"   ,-\"       _,  /                          \\`--...___...--'/   \n"
			"  (     -:--'/  /                           /`--...___...--'\\\n"
			"   \"-._   `\"'._/                           /`---...___...---'\\\n"
			"        \"-._   \"---.                      (`---....___....---')\n"
			"         .' \", ._,' )                     |`---....___....---'| \n"
			"         /`._|  `|  |                     (`---....___....---') \n"
			"        (   \\    |  /                      \\`---...___...---'/\n"
			"         `.  `,  ^\"\"                        `:--...___...--;'\n"
			"           `.,'                               `-._______.-'\n";

			
		break;
	default:
		break;
	}

	switchLevelScreen(switcher);
}

void game_Over()
{
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t\t||=============||";
	cout << "\n\t\t\t\t\t\t||  GAME OVER  ||";
	cout << "\n\t\t\t\t\t\t||=============||";
	cout << "\n\n\t\t\t\t\t\t    Score: " << score << endl << endl << endl;
}