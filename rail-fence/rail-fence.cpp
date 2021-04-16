#include <iostream>

using namespace std;

string cipher(string &message, int key)
{
	unsigned size = message.size();
	string encodedMsg = "";
	// the distance between elements in the same row, except for the diagonals after the mid point
	const int interval = (2 * (key - 1));
	/*********************************
	 * process by the number of rows *
	 *********************************/
	for (int i = 0; i < key; i++)
	{
		bool flag = false;
		string aux = "";
		// number of chars in this row that are in the first susecion
		int rowLimit = 1 + ((size - 1 - i) / interval);
		// If we aren't at the edge and if there is at least a char in the other susecion
		if ((i != 0 && i != key - 1) && size > interval - i)
		{
			rowLimit += 1 + ((size - 1 - (interval - i)) / interval);
			flag = true;
		}

		// we got the number of characters in the row, that is rowLimit
		for (int j = 0; j < rowLimit; j++)
		{
			if (flag && (j % 2 == 1)) // the other susecion
				aux += message[i + (interval * (j / 2)) + interval - (2 * i)];
			else // main susecion
			{
				if (flag)
					aux += message[i + (interval * j / 2)]; //parse the index
				else
					aux += message[i + (interval * j)];
			}
		}
		encodedMsg += aux;
	}
	return encodedMsg;
}
string cutString(string &str, int start, int end)
{
	string cutStr = "";
	for (int i = start; i < end; i++)
		cutStr += str[i];
	return cutStr;
}

string descipher(string &message, int key)
{
	string decodedMsg = "";
	unsigned size = message.size();
	// the distance between elements in the same row, except for the diagonals after the mid point
	const int interval = (2 * (key - 1));
	unsigned start = 0;
	// we will chunk the main string
	int counters[key];

	// search the start of every chunk and cut it.
	// there is no need to have a limit for every chunk,
	// only to know what's the next index.
	for (int i = 0; i < key - 1; i++)
	{
		counters[i] = start;
		start += 1 + ((size - 1 - i) / interval);
		if ((i != 0) && (i != key))
			start += 1 + (((size - 1 - i) - (interval - (2 * i))) / interval);
	}
	counters[key - 1] = start;

	unsigned counter = 0; // because this is the limit, the size of the message.
	bool breaker = false; // we may reach the limit inside a for loop, this will assure that we break the whole loop
	while (counter < size + 1)
	{
		// first group
		decodedMsg += message[counters[0]];
		counters[0]++;
		counter++;
		if (counter == size)
			break;
		// second group (first susecion)
		for (int i = 1; i < key - 1; i++)
		{
			decodedMsg += message[counters[i]];
			counters[i]++;
			counter++;
			if (counter == size)
			{
				breaker = true;
				break;
			}
		}

		// third group (the last row)
		if (breaker || (counter == size))
			break;
		decodedMsg += message[counters[key - 1]];
		counters[key - 1]++;
		counter++;
		if (counter == size)
			break;

		// fourth group (second susecion)
		for (int i = key - 2; i > 0; i--)
		{
			decodedMsg += message[counters[i]];
			counters[i]++;
			counter++;
			if (counter == size)
			{
				breaker = true;
				break;
			}
		}

		if (breaker || (counter == size))
			break;
	}
	return decodedMsg;
}
class Receiver
{
private:
	int key;

public:
	Receiver(int iKey)
	{
		key = iKey;
	}
	void receiveMessage(string &message)
	{
		cout << descipher(message, key) << endl;
	}
};

class Transmitter
{
private:
	int key;

public:
	Transmitter(int iKey)
	{
		key = iKey;
	}
	string generateMessage(string message)
	{
		return cipher(message, key);
	}
};

int main()
{
	/********************************************************
	 * How I chunked the rail-fence?                        *
	 ********************************************************
	 *  Let's say My key is 4 and my word is "Hello world!" *
	 *  H e l l o - w o r l d !                             *
	 *  H           w                                       *
	 *    e           o                                     *
	 *      l           r                                   *
	 *        l           l                                 *
	 *    we add this susecion                              *
	 *             -          !                             *
	 *          o           d                               *
	 *We must know how many characters are in a row for this*
	 ********************************************************/

	int key = 5;
	Transmitter transmitter(key);
	Receiver receiver(key);
	// string cipheredMsg = transmitter.generateMessage("How are you doing since the 2020 pandemy?");
	// string cipheredMsg = "Hsdo inewgnam ncpyaie ?ro 0edt2  h0yue2o ";
	// string cipheredMsg = "Heo slotama osc";
	// string cipheredMsg = "tscehi ermsei ase sgs ta";
	string cipheredMsg = "GSa aoblngretaii";
	// string cipheredMsg = "Mn--dcsdoeeeeetie-ett--upsc-rhnassbj-imre-ihlgteh-sybd-oo-staay-rtpe-ouot-ttinc-sg-osa-etinoio.iiysn-o-n";
	// string cipheredMsg = transmitter.generateMessage("Hello world!");
	cout << cipheredMsg << endl;
	receiver.receiveMessage(cipheredMsg);

	return 0;
}
