#include "Roll.comlite.cpp"

void Roll::sonRollCXCorrect()
{
    this->sonRoll->cX = this->cX + cos(this->conorToSonRoll) * this->kickDis;
    this->sonRoll->cY = this->cY + sin(this->conorToSonRoll) * this->kickDis;
}

void Roll::sonRollOnPosition()
{
    if (this->sonRoll != nullptr)
    {
        this->sonRollCXCorrect();
        if (!this->sonRotation)
        {
            this->sonRoll->conor += radToDeg(this->sonRotationIndex) * 2;
        }
        else
        {
            this->sonRoll->conor -= radToDeg(this->sonRotationIndex) * 2;
        }
    }
}

void Roll::sonRollRotation()
{
    if (this->sonRoll != nullptr)
    {
        // console.log("rot way = " + to_string(this->sonRotationWay));
        // console.log("liner = " + to_string(this->liner));
        // console.log("this is sonRollRitation");
        // console.log("position = " + to_string(this->sonRollPosition));
        // console.log("rotation = " + to_string(this->sonRotation));
        // console.log("deg = " + to_string(radToDeg(0.1)));
        if (!this->sonRollPosition)
        {
            // Roll *leftVirtualRoll = this->getLeftSonPoint();

            // PointF a = {leftVirtualRoll->cX, leftVirtualRoll->cY};
            // PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            // Delta deltas = getDeltas(a, b);
            // double dis = getDis(deltas);

            if (!this->sonRotation)
            {
                this->conorToSonRoll += this->sonRotationIndex;
                //  console.log("here");
            }
            else
            {
                this->conorToSonRoll -= this->sonRotationIndex;
                // console.log("here 2");
            }

            // this->sonRollCXCorrect();
            // PointF a = {leftVirtualRoll->cX, leftVirtualRoll->cY};
            //  PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            ////   Delta deltas = getDeltas(a, b);
            //   double dis = getDis(deltas);

            //  console.log("left dis = " + to_string(dis));

            //  if (dis > this->saveDisToSon)
            //  {

            // this->game->pause = true;
            //    this->sonRoll->readyInLine = true;
            // b = {this->cX, this->cY};
            // deltas = getDeltas(b, a);
            // this->conorToSonRoll = getConor(deltas);

            // this->sonRoll->leftRoll = this->leftRoll;
            // this->sonRoll->rightRoll = this;
            // this->sonRoll->leftRoll->rightRoll = this->sonRoll;
            // this->leftRoll = this->sonRoll;
            // this->sonRoll->game = this->game;
            // this->sonRoll = nullptr;
            //   }
            // if (this->saveDisToSon > 995)
            // {
            //     this->saveDisToSon--;
            // }
            // else
            // {
            //     this->saveDisToSon = dis;
            // }
            //   delete leftVirtualRoll;

            //  leftVirtualRoll = nullptr;
        }
        else
        {
            // Roll *rightVirtualRoll = this->getRightSonPoint();

            // PointF a = {rightVirtualRoll->cX, rightVirtualRoll->cY};
            // PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            // Delta deltas = getDeltas(a, b);
            // double dis = getDis(deltas);

            if (!this->sonRotation)
            {
                this->conorToSonRoll += this->sonRotationIndex;
                //  console.log("here");
            }
            else
            {
                this->conorToSonRoll -= this->sonRotationIndex;
                //  console.log("here 2");
            }

            // this->sonRollCXCorrect();
            //  PointF a = {rightVirtualRoll->cX, rightVirtualRoll->cY};
            // PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            //  Delta deltas = getDeltas(a, b);
            //  double dis = getDis(deltas);

            // console.log("right dis = " + to_string(dis));

            //  if (dis > this->saveDisToSon)
            //  {

            // this->game->pause = true;
            //    this->sonRoll->readyInLine = true;
            // b = {this->cX, this->cY};
            // deltas = getDeltas(b, a);
            // this->conorToSonRoll = getConor(deltas);
            // this->sonRoll->leftRoll = this;
            // this->sonRoll->rightRoll = this->rightRoll;
            // this->sonRoll->rightRoll->leftRoll = this->sonRoll;
            // this->rightRoll = this->sonRoll;
            // this->sonRoll->game = this->game;
            // this->sonRoll = nullptr;
            //   }
            // if (this->saveDisToSon > 995)
            // {
            //     this->saveDisToSon--;
            // }
            // else
            // {
            //     this->saveDisToSon = dis;
            // }
            // delete rightVirtualRoll;
            // rightVirtualRoll = nullptr;
        }
        this->sonRollOnPosition();
    }
}

void Roll::sonRollProg()
{
    if (this->sonRoll != nullptr)
    {
        Roll *virtualRoll;

        bool out = false;

        if (!this->sonRollPosition)
        {
            virtualRoll = this->getLeftSonPoint();

            PointF a = {virtualRoll->cX, virtualRoll->cY};
            PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);

            double virtualConor = this->conorToSonRoll;

            if (!this->sonRotation)
            {
                virtualConor += 0.1;
            }
            else
            {
                virtualConor -= 0.1;
            }

            b = {this->cX + cos(virtualConor) * this->kickDis,
                 this->cY + sin(virtualConor) * this->kickDis};
            deltas = getDeltas(a, b);
            double virtualDis = getDis(deltas);

            if (dis < virtualDis)
            {
                this->sonRoll->leftRoll = this->leftRoll;
                this->sonRoll->rightRoll = this;
                this->leftRoll->rightRoll = this->sonRoll;
                this->leftRoll = this->sonRoll;
                this->sonRoll->game = this->game;
                out = true;
            }
        }
        else
        {
            virtualRoll = this->getRightSonPoint();

            PointF a = {virtualRoll->cX, virtualRoll->cY};
            PointF b = {this->sonRoll->cX, this->sonRoll->cY};
            Delta deltas = getDeltas(a, b);
            double dis = getDis(deltas);

            double virtualConor = this->conorToSonRoll;

            if (!this->sonRotation)
            {
                virtualConor += 0.1;
            }
            else
            {
                virtualConor -= 0.1;
            }

            b = {this->cX + cos(virtualConor) * this->kickDis,
                 this->cY + sin(virtualConor) * this->kickDis};
            deltas = getDeltas(a, b);
            double virtualDis = getDis(deltas);

            if (dis < virtualDis)
            {
                this->sonRoll->leftRoll = this;
                this->sonRoll->rightRoll = this->rightRoll;
                if (this->sonRoll->rightRoll != nullptr)
                {
                    this->sonRoll->rightRoll->leftRoll = this->sonRoll;
                }
                this->rightRoll = this->sonRoll;
                this->sonRoll->game = this->game;
                out = true;
            }
        }

        if (out)
        {
            // if (this == this->game->rolls2[this->game->rolls2.size() - 1])
            // {
            //    // console.log("here");
            //     this->game->pause = true;
            //     this->game->needForPause = true;
            // }
            // // console.log("sonRoll on position");

            int index;
            for (int i = 0; i < this->game->rolls2.size(); i++)
            {
                if (this->game->rolls2[i] == this)
                {
                    index = i;
                    break;
                }
            }

            this->game->rolls2.emplace(this->game->rolls2.cbegin() + (index + this->sonRollPosition),
                                       this->sonRoll);

            this->sonRoll->leftCont = virtualRoll->leftCont;
            this->sonRoll->rightCont = virtualRoll->rightCont;
            this->sonRoll->cX = virtualRoll->cX;
            this->sonRoll->cY = virtualRoll->cY;
            this->sonRoll->father = false;
            this->sonRoll->readyInLine = false;
            this->game->unComplite = false;
            this->sonRoll->speed = this->speed;
            // this->game->controllRoll = this->sonRoll;
            this->sonRoll = nullptr;
            this->game->rollWithSon = nullptr;
            this->saveDisToSon = 1000;

            this->game->getGroups();
           // this->game->pause = true;
           // console.log("groups length = " + to_string(this->game->groups.size()));
        }

        delete virtualRoll;
        virtualRoll = nullptr;
    }
}