#include "EnemyBullet.h"
#include "KamataEngine.h"
#include"MapChipField.h"
#include"Enemy.h"
#include"GameScene.h"

using namespace KamataEngine;
using namespace MathUtility;




void EnemyBullet::Initialize(KamataEngine::Model* model, Camera* camera, const KamataEngine::Vector3& position, const KamataEngine::Vector3& velocity)
{
	// NULLポイントチェック
	assert(model);

	model_ = model;

	camera_ = camera;

	// 速度を引数で受け取って初期化
	velocity_ = velocity;

	// 引数で受け取った初期座標をリセット
	worldTransform_.translation_ = position;

	// ワールド変換データ初期化
	worldTransform_.Initialize();

	// Bulletvelocity_ = velocity;
}

void EnemyBullet::Update() 
{
	// 弾を移動
	worldTransform_.translation_ -= velocity_;

	// アフィン変換行列
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix(); // 敵の座標の計算
}

void EnemyBullet::Draw() 
{

	// モデルの描画
	model_->Draw(worldTransform_, *camera_);

	// 終了なら何もしない
	if (isFinished_)
	{
		return;
	}
}
