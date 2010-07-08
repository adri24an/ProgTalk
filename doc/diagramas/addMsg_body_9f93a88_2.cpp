std::map<string, Message *>::const_iterator
  mit (messages.begin()),
  mend(messages.end());
int id = 0;

for(;mit!=mend;++mit) 
  {
    if ((mit->first.compare(m->get_mid)) == 0)
      {
	std::cout << "Error: the mid (" << m->mid << 
	  ") used in the message already exists" << std::endl;
	exit(0);
      }
  }

messages[m->mid] = m;
