#include "PlayerBullet.h"
#include "KamataEngine.h"


using namespace KamataEngine;
using namespace MathUtility;

void PlayerBullet::Initialize(KamataEngine::Model* model, Camera* camera, const KamataEngine::Vector3& position)
{ 
	// NULLポイントチェック
	assert(model);
	
	model_ = model;
	
	
	camera_ = camera;


	// ワールド変換データ初期化
	worldTransform_.Initialize();
	
	//引数で受け取った初期座標をリセット
	worldTransform_.translation_ = position;


	//Bulletvelocity_ = velocity;
}

void PlayerBullet::Update()
{
	//座標を移動させる
	worldTransform_.translation_ += Bulletvelocity_;
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();

	if (--deathTimer <= 0)
	{
		isDead_ = true;
	}
}


void PlayerBullet::Draw(const KamataEngine::Camera& camera)
{
	
	//モデルの描画
	model_->Draw(worldTransform_, *camera_);
}

