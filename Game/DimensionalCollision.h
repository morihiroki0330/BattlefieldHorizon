#pragma once
struct ObjectData
{
	int ObjectName = 0;//�I�u�W�F�N�g�̖��O
	int Tag = 0;//�I�u�W�F�N�g�̃^�O
	int Direction = 0;//�I�u�W�F�N�g�̋����
	float UpperLeftVertexPositionX = 0;//��`�̍���X
	float UpperLeftVertexPositionY = 0;//��`�̍���Y
	float LowerRightVertexPositionX = 0;//��`�̉E��X
	float LowerRightVertexPositionY = 0;//��`�̉E��Y
	float Wide = 0;
	float Height = 0;
};
enum
{
	DIRECTION_NON = 0,
	DIRECTION_UP = 1,
	DIRECTION_RIGHT = 2,
	DIRECTION_DOWN = 3,
	DIRECTION_LEFT = 4
};
class DimensionalCollision : public IGameObject
{
public:

	DimensionalCollision();
	void Reset();

	//�����蔻��̐���
	void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag);
	void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag, int& Number);

	//�����蔻��̍폜
	void DecisionDataDelete(int ObjectName);

	//�R�s�[
	bool CopyDecisionData(ObjectData& Decision, int ObjectName);//�y�{�́z�̃R�s�[
	bool CopyDecisionsData(ObjectData& Decision, int Tag, int Count);//�y�^�O���t���������̖{�́z�̃R�s�[
	bool CopyEmptyData(ObjectData& Decision, int ObjectName, int Direction);//�y��z�̃R�s�[
	bool CopyEmptysData(ObjectData& Decision, int Tag, int Direction, int Count);//�y�^�O���t���������̋�z�̃R�s�[

	//���W�X�V
	void DecisionSetPosition(float PositionX, float PositionY, int ObjectName);
	void DecisionSetPosition(float PositionX, float PositionY, int ObjectName, int Number);

	//�Փ˔���
	bool EmptyAndEmptyCollision(int ObjectName1, int Direction1, int ObjectName2, int Direction2);//�y�󓯎m�z�̏Փ�
	bool DecisionAndDecisionCollision(int ObjectName1, int ObjectName2);//�y�{�̓��m�z�̏Փ�

	bool EmptyAndDecisionCollision(int ObjectName1, int Direction1, int ObjectName2);//�y��z�Ɓy�{�́z�̏Փ�

	bool EmptyAndDecisionsCollision(int ObjectName1, int Direction1, int Tag2);//�y��z�Ɓy�^�O���t���������̖{�́z�̏Փ�
	bool DecisionAndDecisionsCollision(int ObjectName1, int Tag2);//�y�{�́z�Ɓy�^�O���t���������̖{�́z�̏Փ�

	bool EmptyAndEmptysCollision(int ObjectName1, int Direction1, int Tag2, int Direction2);//�y��z�Ɓy�^�O���t���������̋�z�̏Փ�
	bool DecisionAndEmptysCollision(int ObjectName1, int Tag2, int Direction2);//�y�{�́z�Ɓy�^�O���t���������̋�z�̏Փ�

	bool DecisionAndDecisionsCollision(int ObjectName1, int Tag2, int Number);//�y�{�́z�Ɓy�w��^�O���t���������̖{�́z�̏Փ�
	bool EmptysAndEmptysCollision(int Tag1, int Direction1, int Number1, int Tag2, int Direction2);//�y�w��^�O���t���������̋�z�Ɓy�^�O���t���������̋�z�̏Փ�


	int OddConversion(int Number)
	{
		if (Number % 2 == 0)
		{
			return Number += 1;
		}
		else {
			return Number;
		}
	}
	int EvenConversion(int Number)
	{
		if (Number % 2 == 1)
		{
			return Number += 1;
		}
		else {
			return Number;
		}
	}

	Vector4 GetWidth()
	{
		return CollisionWidth;
	}
private:
	void DecisionInSideDataSet(int Count);
	void DecisionUpSetPosition(int Count);
	void DecisionRightSetPosition(int Count);
	void DecisionDownSetPosition(int Count);
	void DecisionLeftSetPosition(int Count);
public:
	ObjectData DecisionData[256][5];
	float EmptyWidth = 15.0f;
	float InitValue = 50000.0f;
	Vector4 CollisionWidth;//X:��̏��Y:�E�̏Փ�Z:���̏Փ�W:���̏Փ�
};

