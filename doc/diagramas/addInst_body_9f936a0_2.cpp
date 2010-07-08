std::map<string, Instance *>::const_iterator
  mit (instances.begin()),
  mend(instances.end());

for(;mit!=mend;++mit) 
  {
    if ((mit->first.compare(i->get_iid)) == 0)
      {	
	std::cout << "Error: The instance already exists." << std::endl;
	exit(0); 
      }
  }

instances[i->iid] = i;
