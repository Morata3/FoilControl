#include <unistd.h>
#include <cstdio>

#include <Navio2/RCInput_Navio2.h>
#include <Navio+/RCInput_Navio.h>
#include <Common/Util.h>
#include <memory>

#define READ_FAILED -1

std::unique_ptr <RCInput> get_rcin()
{
    if (get_navio_version() == NAVIO2)
    {
        auto ptr = std::unique_ptr <RCInput>{ new RCInput_Navio2() };
        return ptr;
    } else
    {
        auto ptr = std::unique_ptr <RCInput>{ new RCInput_Navio() };
        return ptr;
    }

}


int main(int argc, char *argv[])
{
    if (check_apm()) {
        return 1;
    }

    auto rcin = get_rcin();

    rcin->initialize();

    while (true)
    {
        int period = rcin->read(2);
	int period2= rcin->read(1);
	int period3= rcin->read(3);
	int period4=rcin -> read(4);
        if (period == READ_FAILED)
            return EXIT_FAILURE;
	if (period2== READ_FAILED)
		   EXIT_FAILURE;
	if(period3==READ_FAILED)
		   EXIT_FAILURE;
	if(period4==READ_FAILED)
		   EXIT_FAILURE;

        printf("Y IZ: %d\n", period);
	printf("Y DER: %d\n", period2);
	printf("X IZ: %d\n", period3);
	printf("X DER: %d\n", period4);	        
        sleep(1);
    }

    return 0;
}

