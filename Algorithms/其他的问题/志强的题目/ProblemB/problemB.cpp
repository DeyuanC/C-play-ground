#include <iostream>
#include <string>
#include <iomanip>

struct unit_info
{
	int dist;
	std::string original_unit;
	std::string certain;
	std::string changed_unit;
	//char original_unit[10];
	//char certain[10];
	//char changed_unit[10];
};

int main() 
{
	unit_info distance;
	std::cin >> distance.dist;
	std::cin >> distance.original_unit;
	std::cin >> distance.certain;
	std::cin >> distance.changed_unit;
	//scanf_s("%d %s %s %s", &distance.dist, &distance.original_unit[0], &distance.certain[0], &distance.changed_unit[0]);

	double output;
	int flag = -1;

	if (distance.original_unit == "thou" || distance.original_unit == "th")
		flag = 1;
	else if (distance.original_unit == "inch" || distance.original_unit == "in")
		flag = 2;
	else if (distance.original_unit == "foot" || distance.original_unit == "ft")
		flag = 3;
	else if (distance.original_unit == "yard" || distance.original_unit == "yd")
		flag = 4;
	else if (distance.original_unit == "chain" || distance.original_unit == "ch")
		flag = 5;
	else if (distance.original_unit == "furlong" || distance.original_unit == "fur")
		flag = 6;
	else if (distance.original_unit == "mile" || distance.original_unit == "mi")
		flag = 7;
	else if(distance.original_unit == "league" || distance.original_unit == "lea")
		flag = 8;

	switch (flag)
	{
		// thou
	case 1:
		if (distance.changed_unit == "inch" || distance.changed_unit == "in")
			output = (double)distance.dist/1000;
		else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
			output = (double)distance.dist / 1000 / 12;
		else if (distance.changed_unit == "yard" || distance.changed_unit == "yd")
			output = (double)distance.dist / 1000 / 12 / 3;
		else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
			output = (double)distance.dist / 1000 / 12 / 3 / 22;
		else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
			output = (double)distance.dist / 1000 / 12 / 3 / 22 / 10;
		else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
			output = (double)distance.dist / 1000 / 12 / 3 / 22 / 10 / 8;
		else if (distance.changed_unit == "league" || distance.changed_unit == "lea")
			output = (double)distance.dist / 1000 / 12 / 3 / 22 / 10 / 8 / 3;
		break;


		//inch
	case 2:
		if (distance.changed_unit == "thou" || distance.changed_unit == "th")
			output = (double)distance.dist*1000;
		else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
			output = (double)distance.dist/ 12;
		else if (distance.changed_unit == "yard" || distance.changed_unit == "yd")
			output = (double)distance.dist / 12 / 3;
		else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
			output = (double)distance.dist / 12 / 3 / 22;
		else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
			output = (double)distance.dist/ 12 / 3 / 22 / 10;
		else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
			output = (double)distance.dist/ 12 / 3 / 22 / 10 / 8;
		else if(distance.changed_unit == "league" || distance.changed_unit == "lea")
			output = (double)distance.dist/ 12 / 3 / 22 / 10 / 8 / 3;
		break;

		//foot
	case 3:
		if (distance.changed_unit == "thou" || distance.changed_unit == "th")
			output = (double)distance.dist * 1000*12;
		else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
			output = (double)distance.dist * 12;
		else if (distance.changed_unit == "yard" || distance.changed_unit == "yd")
			output = (double)distance.dist/ 3;
		else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
			output = (double)distance.dist/3 / 22;
		else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
			output = (double)distance.dist/ 3 / 22 / 10;
		else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
			output = (double)distance.dist / 3 / 22 / 10 / 8;
		else if (distance.changed_unit == "league" || distance.changed_unit == "lea")
			output = (double)distance.dist/3 / 22 / 10 / 8 / 3;
		break;

		//yard
	case 4:
		if (distance.changed_unit == "thou" || distance.changed_unit == "th")
			output = (double)distance.dist *1000*12*3;
		else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
			output = (double)distance.dist * 12*3;
		else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
			output = (double)distance.dist * 3;
		else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
			output = (double)distance.dist / 22;
		else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
			output = (double)distance.dist / 22 / 10;
		else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
			output = (double)distance.dist / 22 / 10 / 8;
		else if(distance.changed_unit == "league" || distance.changed_unit == "lea")
			output = (double)distance.dist / 22 / 10 / 8 / 3;
		break;

		//chain
	case 5:
			if (distance.changed_unit == "thou" || distance.changed_unit == "th")
				output = (double)distance.dist *22 * 3*12 *1000;
			else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
				output = (double)distance.dist *22* 3* 12;
			else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
				output = (double)distance.dist*22*3 ;
			else if (distance.changed_unit == "yard" || distance.changed_unit == "ya")
				output = (double)distance.dist * 22;
			else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
				output = (double)distance.dist / 10;
			else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
				output = (double)distance.dist / 10 / 8;
			else if(distance.changed_unit == "league" || distance.changed_unit == "lea")
				output = (double)distance.dist / 10 / 8 / 3;
			break;

	 //furlong
	case 6:
			if (distance.changed_unit == "thou" || distance.changed_unit == "th")
				output = (double)distance.dist *10 * 22 * 3 * 12 * 1000;
			else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
				output = (double)distance.dist *10 * 22 * 3 * 12;
			else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
				output = (double)distance.dist *10 * 22 * 3;
			else if (distance.changed_unit == "yard" || distance.changed_unit == "ya")
				output = (double)distance.dist *10 * 22;
			else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
				output = (double)distance.dist *10 ;
			else if (distance.changed_unit == "mile" || distance.changed_unit == "mi")
				output = (double)distance.dist / 8;
			else if(distance.changed_unit == "league" || distance.changed_unit == "lea")
				output = (double)distance.dist / 8 / 3;
		
			break;
	//mile
	case 7:
			if (distance.changed_unit == "thou" || distance.changed_unit == "th")
				output = (double)distance.dist *8 * 10 * 22 * 3 * 12 * 1000;
			else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
				output = (double)distance.dist *8* 10 * 22 * 3 * 12;
			else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
				output = (double)distance.dist *8* 10 * 22 * 3;
			else if (distance.changed_unit == "yard" || distance.changed_unit == "ya")
				output = (double)distance.dist *8* 10 * 22;
			else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
				output = (double)distance.dist * 8*10;
			else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
				output = (double)distance.dist * 8;
			else if(distance.changed_unit == "league" || distance.changed_unit == "lea")
				output = (double)distance.dist / 3;
			break;
 //league
	case 8:
			if (distance.changed_unit == "thou" || distance.changed_unit == "th")
				output = (double)distance.dist * 3* 8 * 10 * 22 * 3 * 12 * 1000;
			else if (distance.changed_unit == "inch" || distance.changed_unit == "in")
				output = (double)distance.dist * 3*8 * 10 * 22 * 3 * 12;
			else if (distance.changed_unit == "foot" || distance.changed_unit == "ft")
				output = (double)distance.dist * 3*8 * 10 * 22 * 3;
			else if (distance.changed_unit == "yard" || distance.changed_unit == "ya")
				output = (double)distance.dist * 3*8 * 10 * 22;
			else if (distance.changed_unit == "chain" || distance.changed_unit == "ch")
				output = (double)distance.dist *3* 8 * 10;
			else if (distance.changed_unit == "furlong" || distance.changed_unit == "fur")
				output = (double)distance.dist *3* 8;
			else if(distance.changed_unit == "mile" || distance.changed_unit == "mi")
				output = (double)distance.dist * 3;
			break;
   }

  std::cout <<output << std::endl;

  return 0;
  }