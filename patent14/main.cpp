#include "patent.h"

int main()
{
	Patent patent;

	/** ¶ÁÈ¡csvÎÄ¼ş */
	patent.ReadCSV();

	/***/
	patent.ManageD();

	patent.ManageR();

	patent.ManageIndex();

	patent.WriteJson();

	return 0;
}