#include "patent.h"

int main()
{
	Patent patent;

	/** ��ȡcsv�ļ� */
	patent.ReadCSV();

	/***/
	patent.ManageD();

	patent.ManageR();

	patent.ManageIndex();

	patent.WriteJson();

	return 0;
}