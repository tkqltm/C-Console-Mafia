// asdasd.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "asdasd.h"

enum Job { HUMAN, POLICE, DOCTOR, MAFIA };

struct User
{
	char name[20];
	enum Job job;
	_Bool isAlive;
	_Bool isDay;
	int Point;
};

struct User user[11];

int main()
{
	Start();
}

int Start()
{
	printf("Ai 마피아 게임에 오신걸 환영합니다.\n");
	while (1)
	{
		printf("아래의 명령어를 입력해주세요.\n");
		printf("1. 게임 설명듣기\n");
		printf("2. 게임 시작하기\n");
		printf("3. 게임 종료하기\n");

		int Input = 0;

		printf("명령어 입력: ");
		scanf_s("%d", &Input);

		if (Input == 1)
		{
			rule_Help();
		}
		else if (Input == 2)
		{
			SetPlayer();
			Job_Choice();
			ShowInMyJob();
			Day_Morning();
			Day_Night();
		}
		else if (Input == 3)
		{
			system("cls");
			printf("게임을 종료합니다.\n");
			break;
		}
		else
		{
			printf("잘못된 입력입니다. 명령어를 다시 확인해주세요.\n");
		}
		break;
	}
}

int SetPlayer()
{
	printf("게임을 시작합니다. 참가자를 선출하겠습니다.\n");
	char* members[11] = { "전소미0","김세정1","최유정2", "김청하3", "김소혜4", "주결경5", "정채연6", "김도연7", "강미나8", "임나영9", "유연정10" };

	srand(time(NULL));

	printf("마피아 게임의 참가자들 명단입니다.\n\n");

	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 5;
		user[i].isAlive = 1;
		strcpy_s(user[i].name, 11, members[random]);
		printf("[");
		printf("%s", user[i].name);
		printf("] ");
	}
	printf("직업을 지정하겠습니다.\n");
}

int rule_Help()
{
	printf("마피아는 매 턴 마다 시민을 죽일 수 있습니다.\n");
	printf("경찰은 매 턴 마다 직업을 조사 할 수 있습니다.\n");
	printf("의사는 매 턴 마다 지목한 유저를 살릴 수 있습니다.\n");
	printf("시민은 의사소통만으로 마피아를 찾아야 합니다.\n");
}

int Job_Choice()
{
	// 랜덤 함수를 사용하기 위한 시드 생성
	srand(time(NULL));

	// 모든 사람을 시민으로 초기화
	for (int i = 0;i < 5;i++)
	{
		user[i].job = HUMAN;
	}
	printf("마피아를 선택합니다.\n\n");
	// 마피아 선택
	int randomMafia = rand() % 5;
	user[randomMafia].job = MAFIA;

	printf("마피아를 선택 했습니다.\n\n");
	printf("다음 직업할 사람을 지목중...\n\n");

	// 경찰 선택
	while (1)
	{
		int randomPolice = rand() % 5;

		if (user[randomPolice].job == HUMAN)
		{
			user[randomPolice].job = POLICE;
			printf("경찰을 선택 했습니다.\n\n");
			printf("다음 직업할 사람을 지목중...\n\n");
			break;
		}
	}

	while (1)
	{
		int randomDoctor = rand() % 5;

		if (user[randomDoctor].job == HUMAN)
		{
			user[randomDoctor].job = DOCTOR;
			printf("의사를 선택 했습니다.\n\n");
			break;
		}
	}

	for (int i = 0; i < 5; i++) // 직업 표시
	{
		printf("%d", user[i].job);
		printf("\n)
	}
}

int Dead()
{
	//if (user_info.isAlive = 0)
	//	printf("당신은 투표에 의해 사망 하였습니다.");
	//else if (user_info.isAlive = 1)
	//	printf("당신은 마피아에게 사망 하였습니다.");
}

int ShowInMyJob()
{
	if (user[0].job == HUMAN)
	{
		printf("당신은 선량한 시민입니다.\n");
		printf("누가 마피아인지 찾아야합니다.\n");
	}
	else if (user[0].job == POLICE)
	{
		printf("당신은 경찰입니다.\n");
		printf("직업 조사를 통해 마피아를 찾을 수 있습니다.\n");
	}
	else if (user[0].job == DOCTOR)
	{
		printf("당신은 의사 입니다.\n");
		printf("밤이되면 살릴 사람을 지목해주세요.\n");
	}
	else if (user[0].job == MAFIA)
	{
		printf("당신은 마피아 입니다.\n");
		printf("밤이되면 죽일 사람을 지목해주세요.\n");
	}
}

int Day_Night()
{
	user->isDay = 1;
	printf("밤이 되었습니다.\n");

	printf("기술을 사용할 대상을 지목해주세요.\n\n");
	Job_Police();
	if (Job_Doctor() == Job_Mafia())
	{
		printf("의사가 [%s]님을 마피아의 공격으로부터 살리셨습니다.\n",user->name);
		user->isAlive = 1;
	}

}

int Day_Morning()
{
	user->isDay = 0;
	printf("아침이 되었습니다.\n");

	printf("투표를 진행합니다.\n");

	VoteChoice();
}

int Job_Police()
{
	int PoliceScan = rand() % 4;
	if (user[PoliceScan].job == 0)
	{
		printf("[%s]님은 선량한 시민입니다.\n", user[PoliceScan].name);
	}
	else if (user[PoliceScan].job == 1)
	{
		printf("[%s]님은 경찰입니다.\n", user[PoliceScan].name);
	}
	else if (user[PoliceScan].job == 2)
	{
		printf("[%s]님은 의사 입니다.\n", user[PoliceScan].name);
	}
	else if (user[PoliceScan].job == 3)
	{
		printf("[%s]님은 마피아 입니다.\n",user[PoliceScan].name);
	}
}

int Job_Doctor()
{
	int DoctorHealing = rand() % 4;


	if (user[DoctorHealing].isAlive == 1)
	{
		switch (DoctorHealing)
		{
		case 0:
			user[0].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[0].name);
			break;
		case 1:
			user[1].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[1].name);
			break;
		case 2:
			user[2].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[2].name);
			break;
		case 3:
			user[3].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[3].name);
			break;
		case 4:
			user[4].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[4].name);
			break;
		case 5:
			user[5].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[5].name);
			break;
		case 6:
			user[5].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[5].name);
			break;
		case 7:
			user[7].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[7].name);
			break;
		case 8:
			user[8].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[8].name);
			break;
		case 9:
			user[9].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[9].name);
			break;
		case 10:
			user[5].isAlive = 1;
			printf("의사는 [%s]님을 살리셨습니다.\n", user[5].name);
			break;
		}
	}
	return DoctorHealing;
}

int Job_Mafia()
{
	int Mafiakill = rand() % 4;

	switch (Mafiakill)
	{
	case 0:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 1:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 2:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 3:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 4:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 5:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 6:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 7:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 8:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 9:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	case 10:
			printf("[%s] 님은 마피아에게 사망했습니다.\n", user[Mafiakill].name);
			user[Mafiakill].isAlive = 0;
		break;
	}
	return Mafiakill;
}

int VoteChoice()
{
	user->Point = 1;
	printf("투표를 시작하겠습니다.\n");
	printf("마피아로 의심가는 사람을 지목해주세요.\n");
	printf("과반수의 투표를 얻게 되신다면 사망입니다.\n");

	for (int i = 0; i < 5; i++)
	{
		int VoteUser = rand() % 4;
		user[i].Point += i;
		printf("%s 님이 %s 님을 투표 하셨습니다. 받은수: %d\n", user[i].name, user[VoteUser].name, user[VoteUser].Point);
	}
	printf("투표를 종료합니다.\n");

}