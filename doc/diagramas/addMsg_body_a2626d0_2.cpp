std::map<int, Message *>::const_iterator
  mit (messages.begin()),
  mend(messages.end());
int id = 0;

if ((strcmp (m->mid, "No_Info_Available")) != 0)
  {
    for(;mit!=mend;++mit) 
      {
	if ((strcmp(mit->second->get_mid, m->get_mid)) == 0)
	  {
	    std::cout << "Error: the mid (" << m->mid << 
	      ") used in the message already exists" << std::endl;
	    exit(0);
	  }
      }
  }

id = (int) messages.size();
messages[id] = m;
