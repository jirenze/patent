#include "patent.h"
#include <iomanip>

int main()
{
	Patent patent;

	///** ¶ÁÈ¡csvÎÄ¼ş */
	//patent.ReadCSV();

	///***/
	//patent.ManageD();

	//patent.ManageR();

	////patent.ManageWZ();

	//patent.ManageIndex();

	patent.WriteJson();

	return 0;
}