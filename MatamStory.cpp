
#include "MatamStory.h"

#include "Utilities.h"

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    eventmake(eventsStream);
    playermake(playersStream);
    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {
    int EventIndex = (m_turnIndex-1)%(m_events.size());
    printTurnDetails(m_turnIndex, player, *(m_events[EventIndex]));
    m_events[EventIndex]->applyEvent(player);
    cout<<endl;
    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for(auto& player : m_players){
        if(player->getHealthPoints() > 0){
            playTurn(*player);
        }
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    vector<Player*> temp;
    for(auto& player : m_players){
        Player* p=new Player(player->getName(),"Warrior","Responsible");
        p->addCoins(-p->getCoins()+player->getCoins());
        while (p->getLevel()!=player->getLevel())
            p->levelUp();
        p->buff(-p->getForce()+player->getForce());
        p->damage(p->getHealthPoints()-player->getHealthPoints());
        temp.push_back(p);
    }
    mtmSort(&temp);
    for(size_t i = 0; i < m_players.size(); i++){
        printLeaderBoardEntry(i+1, *(temp[i]));
    }
    for(auto& player : temp){
        delete player;
    }
    /*=======================================================================================*/

    printBarrier();
}


bool MatamStory::isGameOver() const {
    bool knockedOut = true;
    for(auto& player : m_players){
        if(player->getLevel() == 10){
            return true;
        }
        if(player->getHealthPoints() != 0){
            knockedOut = false;
        }
    }
    if(knockedOut){
        return true;
    }
    return false;
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    for(size_t i = 0; i < m_players.size(); i++){
        printStartPlayerEntry(i+1, *(m_players[i]));
    }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    for(auto& player : m_players){
        if(player->getLevel() == 10){
            vector<Player*> temp;
            for(auto& player : m_players){
                Player* p=new Player(player->getName(),"Warrior","Responsible");
                p->addCoins(-p->getCoins()+player->getCoins());
                while (p->getLevel()!=player->getLevel())
                    p->levelUp();
                p->buff(-p->getForce()+player->getForce());
                p->damage(p->getHealthPoints()-player->getHealthPoints());
                temp.push_back(p);
            }
            mtmSort(&temp);
            printWinner(*(temp[0]));
            for(auto& player : temp){
                delete player;
            }
            return;
        }
    }
    printNoWinners();
    /*========================================================================*/
}
}


void MatamStory::Aux_lesslines(string* arr,int j,int& size,int& flag,int& s,int& temp_power,int& temp_damage,int&temp_loot,int& flag_k,int& k )
{
    if(arr[k]=="Goblin")
    {
        if(size!=0){
            temp_power+=5;
            temp_loot+=2;
            temp_damage+=10;
            size--;}
        else {
            m_cards.push_back(std::unique_ptr<Goblin>(new Goblin()));
        }
    }
    else
    if(arr[k]=="Dragon")
    { if(size!=0) {
            temp_power += 17;
            temp_loot += 100;
            temp_damage += 9001;
            size--;
        }
        else{
            m_cards.push_back(std::unique_ptr<Dragon>(new Dragon()));
        }
    }
    else if(arr[k]=="Giant")
    { if(size!=0) {
            temp_power += 12;
            temp_loot += 5;
            temp_damage += 25;
            size--;
        }
        else{
            m_cards.push_back(std::unique_ptr<Giant>(new Giant()));
        }
    }
    else if (arr[k] == "SolarEclipse"&& flag!=1) {
        m_cards.push_back(std::unique_ptr<SolarEclipse>(new SolarEclipse()));
    }
    else if (arr[k] == "PotionsMerchant"&&flag!=1) {
        m_cards.push_back(std::unique_ptr<PotionsMerchant>(new PotionsMerchant()));
    }

    else if(arr[k]=="Gang"&&size!=0){
        k--;
    }
    else{
        throw InvalidCardsFile();
    }

}
void MatamStory::Aux_func(string* arr,int j,int& size,int& flag,int& s,int& temp_power,int& temp_damage,int&temp_loot,int& flag_k )
{

    for (int k = 0; k < j; ++k) {
        if(arr[k]=="Gang"|| size!=0||flag_k==-1)
        {
            if(arr[k]=="Gang"&&k+1==j)
            {
                flag_k=-1;
                return;
            }
            if((flag_k==-1&&std::stoi(arr[0])<2)||(arr[k]=="Gang"&&std::stoi(arr[k+1])<2))
            {
                throw InvalidCardsFile();
            }
            if(size==0&&(arr[k]=="Gang"||flag_k==-1))
            {   k=flag_k==-1?-1:k;
                flag_k=1;
                s=std::stoi(arr[k+1]);
                size+=s;
                k+=2;
                flag=1;
            }
            else if(arr[k]=="Gang"||flag_k==-1) {
                if(flag_k==-1)
                {
                    size += size==0 ? std::stoi(arr[0]) : std::stoi(arr[0])-1;
                    flag_k=1;
                }
                else {
                    size += size == 0 ? std::stoi(arr[k + 1]) : std::stoi(arr[k + 1]) - 1;
                    k+=1;
                }
                k += 1;
            }
        }
        Aux_lesslines(arr,j,size,flag,s,temp_power,temp_damage,temp_loot,flag_k,k);

        if(size==0&&flag){
            m_cards.push_back(unique_ptr<Gang>(unique_ptr<Gang>(new Gang(temp_power,temp_loot,temp_damage,s))));
            temp_damage=0;
            temp_loot=0;
            temp_power=0;
            flag=0;
        }
    }
}
void MatamStory::cardmake(const string& Path)
{
    std::ifstream source(Path);
    if (!source) {
        throw InvalidCardsFile();
    }
    std::string cardName,word,c;
    int i=0,temp_power=0,temp_loot=0,temp_damage=0,j=0,size=0,flag=0,s,flag_kk=1;

    while(getline(source,cardName)){

        i=0,j=0;
        istringstream iss(cardName);
        while (iss >> word) {
            i++;
        }
        string* arr=new string [i];
        iss.clear();
        iss.seekg(0, ios::beg);
        while (iss >> c) {
            arr[j]=c;
            j++;
        }
        try {
            if(size!=0)
                flag=1;
            Aux_func(arr, j, size, flag, s, temp_power, temp_damage, temp_loot, flag_kk);
        }
        catch (...)
        {
            delete[] arr;
            throw InvalidCardsFile();
        }
        delete[] arr;
    }
    if(m_cards.size()<2)
        throw InvalidCardsFile();
}
static bool islegalchars(string& name)
{
    for (int i = 0; (unsigned)i < name.size(); ++i) {
        if(!(name[i]<='z'&&name[i]>='a')&&!(name[i]<='Z'&&name[i]>='A'))
            return false;
    }
    return true;
}
void MatamStory::playermake(const string& Path) {
    ifstream source2(Path);
    if (!source2) {
        throw InvalidPlayersFile();
    }
    std::string playerName,word;
    string playerstt[3];
    while(getline(source2,playerName))
    {
        for (int i = 0; i <3 ; ++i) {
            playerstt[i]=" ";
        }
        if(m_players.size()==6)
            throw InvalidPlayersFile();
        istringstream iss(playerName);
        int j = 0;

        while (iss >> word) {
            if(j==3)
                throw InvalidPlayersFile();
            playerstt[j] = word;
            j++;
        }
        if(playerstt[0].size()>15 || !islegalchars(playerstt[0]))
            throw InvalidPlayersFile();
        m_players.push_back(std::unique_ptr<Player>(new Player(playerstt[0],playerstt[1],playerstt[2])));

    }
    if(m_players.size()<2){
        throw InvalidPlayersFile();
    }

}


void MatamStory::mtmSort(vector<Player*>* temp){

    sort(temp->begin(), temp->end(), [](const Player* p1, const Player* p2) {
        if (p1->getLevel() != p2->getLevel()) {
            return p1->getLevel() > p2->getLevel();
        } else if (p1->getCoins() != p2->getCoins()) {
            return p1->getCoins() > p2->getCoins();
        } else {
            return p1->getName() < p2->getName();
        }
    });
}
