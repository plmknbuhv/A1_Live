// Fill out your copyright notice in the Description page of Project Settings.


#include "A1Actor.h"
#include "A1Object.h"

// Sets default values
AA1Actor::AA1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AA1Actor::BeginPlay()
{
	Super::BeginPlay();

	Obj = NewObject<UA1Object>();
}

// Called every frame
void AA1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Obj == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("A1Object Deleted!"));
	}
}

