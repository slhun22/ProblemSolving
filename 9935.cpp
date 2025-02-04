#include <iostream>
#include <list>

using namespace std;

list<char> stack;
char input[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char bomb[37];
	cin >> input >> bomb;
	int i, j, bombLength, cnt = 0;

	for (i = 0; i < 37; i++)
		if (bomb[i] == '\0')
		{
			bombLength = i;
			break;
		}
		

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == bomb[cnt])
		{
			if (cnt == 0)
				stack.push_back('+');

			if (cnt == bombLength - 1)
			{
				while (stack.back() != '+')
				{
					stack.pop_back();
				}
				stack.pop_back();

				if (!stack.empty() && stack.back() == '*')
				{
					stack.pop_back();
					int beforeCnt = 0;
					int multiplier = 1;
					while (stack.back() != '*')
					{
						beforeCnt += (stack.back() - 48) * multiplier;
						multiplier = 10;
						stack.pop_back();
					}
					stack.pop_back();
					cnt = beforeCnt;
				}

				else
					cnt = 0;
			}
			else
			{
				cnt++;
				stack.push_back(input[i]);
			}
		}
		else
		{
			if (cnt > 0)
			{
				stack.push_back('*');
				if (cnt > 9)
					stack.push_back((cnt / 10) + 48);//십의자리
				stack.push_back((cnt % 10) + 48);//일의자리
				stack.push_back('*');
				cnt = 0;
				if (input[i] == bomb[0])
				{
					stack.push_back('+');
					cnt++;
				}
			}
			stack.push_back(input[i]);
		}
		i++;
	}

	if (stack.empty())
		cout << "FRULA";
	else
	{
		i = 0;
		while (!stack.empty())
		{
			if (stack.front() == '*')
			{
				stack.pop_front();
				while(stack.front() != '*')
					stack.pop_front();
				stack.pop_front();
			}

			else if (stack.front() == '+')
				stack.pop_front();

			else
			{
				input[i++] = stack.front();
				stack.pop_front();
			}
		}
		input[i] = '\0';

		cout << input;
	}
}