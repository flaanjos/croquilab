

void splitNumber( unsigned int num, unsigned char& part_1, unsigned char& part_2, unsigned char& part_3 )
{
   part_1 = num % 256;
   num /= 256;
   part_2 = num % 256;
   num /= 256;
   part_3 = num % 256;
}



void mergeNumber( unsigned int& num, unsigned char part_1, unsigned char part_2, unsigned char part_3 )
{
   num = part_3;
   num *= 256;
   num += part_2;
   num *= 256;
   num += part_1;
}

