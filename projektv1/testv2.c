#include <ncurses.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <syscall.h>

WINDOW *full_win, *child_win;//, *child_win2;
int startx, starty, width, height;
char ch;

int threads_names[5];
int counter_tab[5];
int counter = 0;

void sleepsome();
void sleepsomelonger();

void *drop_letter(void *ptr);
void *drop_letter2(void *ptr);
void *drop_letter3(void *ptr);

void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]){

	FILE *log;
	log = fopen("log.txt","a+");

	fprintf(log, "------------LOG OPEN------------\n");

	full_win = initscr();

	keypad(stdscr, TRUE);
	noecho();

	height = 15;
	width = 15;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	if (full_win == NULL) {
			fprintf(log, "Error initialising ncurses.\n");
			exit(EXIT_FAILURE);
	}

	child_win = subwin(full_win, height, width, starty, startx);
	box(child_win,0,0);

	//child_win2 = subwin(full_win, height, width, starty, startx*1.5);
	//box(child_win2,0,0);

	wrefresh(child_win);
	//wrefresh(child_win2);

	pthread_t worker[5];


	int s[5] = {0, 1, 2, 3, 4};


	//wszystkie na raz
			if(pthread_create(&worker[0], NULL, drop_letter, &s[0])){
				fprintf(log, "Error creating thread [0]\n");
				exit(EXIT_FAILURE);
			}
		sleepsome();
			if(pthread_create(&worker[1], NULL, drop_letter3, &s[1])){
				fprintf(log, "Error creating thread [1]\n");
				exit(EXIT_FAILURE);
			}
		sleepsomelonger();
		//sleep(1);
			if(pthread_create(&worker[2], NULL, drop_letter2, &s[2])){
				fprintf(log, "Error creating thread [2]\n");
				exit(EXIT_FAILURE);
			}
		sleepsome();
		//sleep(2);

			if(pthread_create(&worker[3], NULL, drop_letter, &s[3])){
				fprintf(log, "Error creating thread [3]\n");
				exit(EXIT_FAILURE);
			}
		sleepsomelonger();
		//sleep(4);

			if(pthread_create(&worker[4], NULL, drop_letter3, &s[4])){
				fprintf(log, "Error creating thread [4]\n");
				exit(EXIT_FAILURE);
			}

		for(int i = 0; i < 5; i++){
			if (pthread_join(worker[i], NULL)){
				fprintf(log, "Error joining thread [%d]\n", i+1);
				exit(EXIT_FAILURE);
			}
		}


/*		for(int i = 0; i < 5; i++){
			pthread_detach(worker[i]);
		}
*/
		/*if (pthread_join(worker[0], NULL)){
			fprintf(stderr, "Error joining thread1\n");
			exit(EXIT_FAILURE);
		}

		if (pthread_join(worker[1], NULL)){
			fprintf(stderr, "Error joining thread2\n");
			exit(EXIT_FAILURE);
		}

		if (pthread_join(worker[2], NULL)){
			fprintf(stderr, "Error joining thread3\n");
			exit(EXIT_FAILURE);
		}

		if (pthread_join(worker[3], NULL)){
			fprintf(stderr, "Error joining thread3\n");
			exit(EXIT_FAILURE);
		}

		if (pthread_join(worker[4], NULL)){
			fprintf(stderr, "Error joining thread4\n");
			exit(EXIT_FAILURE);
		}*/


	for (int i = 0; i < 5; i++){
		mvwprintw(full_win, i, 0, "Thread %d tid: %d\n", i+1, threads_names[i]);
		fprintf(log, "Thread %d tid: %d\n", i+1, threads_names[i]);
	}

	ch = getch();

	destroy_win(child_win);
	//destroy_win(child_win2);
	destroy_win(full_win);

	endwin();
		fprintf(log, "------------LOG CLOSE------------\n");
	fclose(log);
	
	return 0;
}

void sleepsome(){
	usleep(100000);
	//sleep(1);
}

void sleepsomelonger(){
	usleep(500000);
	//sleep(1);
}

void *drop_letter(void *ptr){


	int ballx, bally;

	int a = 1;
	int b = 7;
	bool flag = false;
	int bounce = 0;

	ballx = b;

	threads_names[counter] = syscall(SYS_gettid);
	counter++;

	for(int i = 0; i < 13; i++){
		bally = a;
		usleep(1000);
    mvwaddstr(child_win, bally, ballx, "a");

		wrefresh(child_win);

		sleepsome();
		//sleep(1);
		usleep(1000);
		mvwaddstr(child_win, bally, ballx, " ");
		wrefresh(child_win);

		if(i == 12) {
			flag = !flag;
			i = 0;
			bounce++;
			if (bounce == 2){
				//mvwaddstr(child_win, bally, ballx, " ");
				break;
			}
		}

		if(flag == true) a--;
		else a++;
	}
}

void *drop_letter2(void *ptr){



	int ballx, bally;

	int a = 1;
	int b = 7;
	bool flag = false;
	int bounce = 0;

	threads_names[counter] = syscall(SYS_gettid);
	counter++;

	for(int i = 0; i < 13; i++){
		bally = a;
		ballx = b;

		usleep(2000);
    mvwaddstr(child_win, bally, ballx, "a");

		wrefresh(child_win);

		sleepsome();
		//sleep(1);
		usleep(2000);
		mvwaddstr(child_win, bally, ballx, " ");
		wrefresh(child_win);

		if(i == 6) {
			flag = !flag;
			i = 0;
			bounce++;
			if (bounce == 2){
				//mvwaddstr(child_win, bally, ballx, " ");
				break;
			}
		}

		if(flag == true) {
			a++;
			b--;
		}
		else {
			a++;
			b++;
		}
	}
}

void *drop_letter3(void *ptr){


	int ballx, bally;

	int a = 1;
	int b = 7;
	bool flag = false;
	int bounce = 0;

	threads_names[counter] = syscall(SYS_gettid);
	counter++;

	for(int i = 0; i < 13; i++){
		bally = a;
		ballx = b;

		usleep(3000);
    mvwaddstr(child_win, bally, ballx, "a");

		wrefresh(child_win);

		sleepsome();
		//sleep(1);
		usleep(3000);
		mvwaddstr(child_win, bally, ballx, " ");
		wrefresh(child_win);

		if(i == 6) {
			flag = !flag;
			i = 0;
			bounce++;
			if (bounce == 2){
				//mvwaddstr(child_win, bally, ballx, " ");
				break;
			}
		}

		if(flag == true) {
			a++;
			b++;
		}
		else {
			a++;
			b--;
		}
	}
}

void destroy_win(WINDOW *local_win){

	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');

	wrefresh(local_win);
	delwin(local_win);
}
