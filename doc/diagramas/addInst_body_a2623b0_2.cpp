std::map<char *, Instance *>::const_iterator
  mit (instances.begin()),
  mend(instances.end());

for(;mit!=mend;++mit) 
  {
    if (!(strcmp(mit->first, i->iid)))
      {	
	std::cout << "Error: The instance already exists." << std::endl;
	exit(0); 
      }
  }

instances[i->iid] = i;
