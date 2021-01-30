// Fill out your copyright notice in the Description page of Project Settings.


#include "TankerBase.h"

#pragma warning (default : 4668)
#undef check
#include "rpc/server.h"
#ifndef check
#define check(expr) (static_cast<void>((expr)))
#endif


ATankerBase::ATankerBase()
{
	UE_LOG(LogTemp, Warning, TEXT("ATanker Constructor"))
}


void ATankerBase::BeginPlay()
{
	Super::BeginPlay();


	if (true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Run rpclib server"))
			/** Create RPC server and binding function**/
			rpc::server *myServer = new rpc::server("127.0.0.1", 18804);

		// Bind Activate skill 
		myServer->bind("Activate_Skill_A", [&]()->void {this->Activate_Skill_A(); });
		myServer->bind("Activate_Skill_B", [&]()->void {this->Activate_Skill_B(); });
		myServer->bind("Activate_Skill_C", [&]()->void {this->Activate_Skill_C(); });
		myServer->bind("Activate_Skill_D", [&]()->void {this->Activate_Skill_D(); });

		// Bind Moving
		myServer->bind("MoveForward", [&](float value)->void {this->MoveForward(value); });
		myServer->bind("MoveRight", [&](float value)->void {this->MoveRight(value); });
//		myServer->bind("Turn", [&](float value)->void {this->Turn(value); });

		myServer->async_run(8);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Do not run rpclib server"))
	}


}
