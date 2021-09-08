int strConteins(char* a, char* str)
{
	int pos = -1;

	int ch = 0;
	while (str[ch] != '\0')
	{
		if (str[ch] == a[0])
		{
			bool have_str = true;
			int j = 0;
			while (a[j] != '\0')
			{
				if (a[j] != str[ch + j])
				{
					have_str = false;
					break;
				}
				j++;
			}
			if (have_str)
			{
				pos = ch;
				break;
			}
		}
		ch++;
	}
	return pos;
}
