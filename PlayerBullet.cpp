#include "PlayerBullet.h"
#include "KamataEngine.h"
#include"MapChipField.h"
#include"Player.h"
#include"GameScene.h"

using namespace KamataEngine;
using namespace MathUtility;

void PlayerBullet::Initialize(KamataEngine::Model* model, Camera* camera, const KamataEngine::Vector3& position)
{ 
	// NULLポイントチェック
	assert(model);
	
	model_ = model;
	
	
	camera_ = camera;


	// 引数で受け取った初期座標をリセット
	worldTransform_.translation_ = position;

	// ワールド変換データ初期化
	worldTransform_.Initialize();
	
	


	//Bulletvelocity_ = velocity;
}

void PlayerBullet::Update()
{
	
	
	// アフィン変換行列
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix(); // プレイヤーの座標の計算
	

	deathTimer--;
	
	if (--deathTimer <= 0)
	{
		isDead_ = true;

	}
}


void PlayerBullet::Draw()
{
	
	//モデルの描画
	model_->Draw(worldTransform_, *camera_);

	// 終了なら何もしない
	if (isFinished_)
	{
		return;
	}
}

