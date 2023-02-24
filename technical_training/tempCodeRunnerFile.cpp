    int start = 0, end = 0;
    int counter = 0;
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == find[0]){
            start = i;
            counter = 1;
            
        }
        if(counter == 1){
            if(sentence[i] == find[find.size() - 1]){
                end = i;
                break;
            }
        }
        
    }
    cout << "Find string at index: " << start << endl;
    sentence.replace(start, find.size(), replace );
    