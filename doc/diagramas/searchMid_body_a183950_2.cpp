std::map<string, Message *>::const_iterator
  mit (messages.begin()),
  mend(messages.end());

for(;mit!=mend;++mit) 
  {
    if ((mit->first.compare(mid)) == 0)
      {	
	return mit->second;
      }
  }

return NULL;
