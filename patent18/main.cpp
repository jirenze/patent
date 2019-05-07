#include "patent.h"

int main()
{
	Patent patent;

	/** 读取csv文件 */
	patent.ReadCSV();
	/***/
	patent.ManageD();

	patent.ManageR();

	patent.ManageIndex();

	patent.WriteJson();

	return 0;
}