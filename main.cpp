#include "patent.h"
#include <iomanip>

int main()
{
	Patent patent;

	/** ��ȡcsv�ļ� */
	patent.ReadCSV();

	/***/
	patent.ManageD();

	patent.ManageR();

	//patent.ManageWZ();

	patent.ManageIndex();

	patent.WriteCSV();

	return 0;
}