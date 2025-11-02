// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/A1_Sphere.h"

// Sets default values
AA1_Sphere::AA1_Sphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));

	Sphere->SetCollisionProfileName(FName("A1Enemy"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT(
		"/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (MeshAsset.Succeeded())
	{
		Sphere->SetStaticMesh(MeshAsset.Object);
	}
	
	SetRootComponent(Sphere);
}

// Called when the game starts or when spawned
void AA1_Sphere::BeginPlay()
{
	Super::BeginPlay();
	
	if (Sphere)
	{
		Sphere->OnComponentHit.AddDynamic(this, &AA1_Sphere::OnSphereHit);
	}
}

// Called every frame
void AA1_Sphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA1_Sphere::OnSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

