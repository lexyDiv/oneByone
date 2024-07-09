#include "../WayLine/WayLine.cpp"


void Game::pushOnRollsOnDelete(Roll *roll)
{
    for (int i = 0; i < 1000; i++)
    {
        Roll *cell = this->rollsOnDelete[i];
        if (cell == nullptr)
        {
            this->rollsOnDelete[i] = roll;
            break;
        }
    }
}

void Game::rollsOnDeleteProg()
{
    for (int i = 0; i < 1000; i++)
    {
        Roll *roll = this->rollsOnDelete[i];
        if (roll != nullptr && roll->del)
        {
            delete roll;
            roll = nullptr;
            this->rollsOnDelete[i] = nullptr;
        }
    }
}

void Game::tryDelProg()
{
    if (this->tryDel && this->unComplite == false && this->rolls2.size() > 35)
    {
        // this->pause = true;
        this->tryDel = false;
        int leftI = 10;
        int rightI = 34;
        Roll *leftRoll = this->rolls2[leftI];
        Roll *rightRoll = this->rolls2[rightI];
        rightRoll->speed = 0;
        leftRoll->speed = 0;
        leftRoll->rightRoll = rightRoll;
        rightRoll->leftRoll = leftRoll;
        // vector<int> indexes;
        for (int i = leftI + 1; i < rightI; i++)
        {
            //  indexes.push_back(i);
            // this->rolls2[i]->show = false;
            this->rolls2[i]->del = true;
            // this->rolls2[i]->cX = 10000;
        }
      
    }
}

void Game::deleter()
{

    for (int i = 0; i < this->rolls2.size(); i++)
    {
        Roll *roll = this->rolls2[i];
        if (
            roll->rightCont == this->wayLine->tale)
        {
            roll->del = true;
            if (roll->sonRoll != nullptr)
            {
                roll->sonRoll->del = true;
                this->rollWithSon = nullptr;
                this->unComplite = false;
            }
        }
        // if (!roll->show)
        // {
        //     double x = roll->cX;
        //     double y = roll->cY;
        //     if (x < 0 || x > ctx.SCREEN_WIDTH || y < 0 || y > ctx.SCREEN_HEIGHT)
        //     {
        //         roll->del = true;
        //         // console.log("need del");
        //     }
        // }
    }

    vector<int> is;
    for (int i = 0; i < this->rolls2.size(); i++)
    {
        Roll *roll = this->rolls2[i];
        if (roll->del)
        {
            is.push_back(i);
        }
    }

    for (int i = 0; i < is.size(); i++)
    {
        Roll *roll = this->rolls2[is[i]];
        roll = nullptr;
        this->rolls2.erase(this->rolls2.cbegin() + is[i] - i);
    }

    this->rollsOnDeleteProg();
    // vector<int> delIndexes;
    // for (int i = 0; i < this->rollsOnDelete.size(); i++)
    // {
    //     Roll *roll = this->rollsOnDelete[i];
    //     if (roll->del)
    //     {
    //         delete roll;
    //         roll = nullptr;
    //         delIndexes.push_back(i);
    //     }
    // }

    // for (int i = 0; i < delIndexes.size(); i++)
    // {
    //     int index = delIndexes[i] - i;
    //     this->rollsOnDelete.erase(this->rollsOnDelete.cbegin() + index);
    // }
}

void Game::getWayLine()
{
    if (!this->wayLine->getLength())
    {
        rapid<WayPoint> arr = fs.read<WayPoint>(this->path, sizeof(WayPoint));
        this->wayLine->update(arr, this->level);
        this->station->getPosition(this->level);
    }
}

void Game::newRollCreating()
{
    double disToImpulseRoll = 0.0f;
    if (this->impulseRoll != nullptr)
    {
        WayPoint *head = this->wayLine->getHead()->wayPoint;
        PointF a = {(double)head->x, (double)head->y};
        PointF b = {(double)this->impulseRoll->cX, (double)this->impulseRoll->cY};
        Delta deltas = getDeltas(a, b);
        disToImpulseRoll = getDis(deltas);
    }

    if (!this->rolls2.size() ||
        (disToImpulseRoll && disToImpulseRoll >= this->rolls2[0]->kickDis)
        // this->rolls->getItem(0)->kickDis)
    )
    {
        if (this->check < 3)
        {
            this->impulseRollCreate();
             this->check++;
        }
    }
}

void Game::rollsToProg()
{

    this->rolls2[this->rolls2.size() - 1]->rightRoll = nullptr;

    for (int i = 1; i < this->rolls2.size(); i++)
    {
        Roll *roll = this->rolls2[i];
        roll->prog(i);
        roll = nullptr;
    }
}

void Game::deleteProg(Roll *roll)
{
    delete roll;
    roll = nullptr;
}

void Game::prog()
{
    // if(this->unComplite || this->needForPause)
    // {
    //     this->pause = true;
    // }
    this->getWayLine();

    this->newRollCreating();



    if (this->impulseRoll != nullptr)
    {
        this->impulseRoll->impulseProg();
    }


    this->rollsToProg();

    this->station->prog();
    this->getRollsToCheckCollision();
    this->flyingMove();
    this->flyingOutDel();

    if (this->rollWithSon != nullptr)
    {
        this->rollWithSon->sonRollProg();
    }

    this->rollsToCollision.clear();
    this->tryDelProg();
    this->deleter();
}

void Game::impulseRollCreate()
{
    Container *head = this->wayLine->getHead();
    Roll *newRoll = new Roll(intRand(1, 6),
                             head->wayPoint->x,
                             head->wayPoint->y);
    // this->rollsOnDelete.push_back(newRoll);
    this->pushOnRollsOnDelete(newRoll);
    this->impulseRoll = newRoll;
    this->rolls2.emplace(this->rolls2.begin(), newRoll);
    newRoll->leftCont = head;
    newRoll->rightCont = head->right;
    newRoll->game = this;
    if (this->rolls2.size() > 1)
    {
        Roll *secondRoll = this->rolls2[1];
        newRoll->rightRoll = secondRoll;
        secondRoll->leftRoll = newRoll;
    }
    newRoll = nullptr;
    head = nullptr;
}
