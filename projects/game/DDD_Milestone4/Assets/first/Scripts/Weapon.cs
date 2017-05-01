using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class Weapon : MonoBehaviour {

	public float fireRate = 0;
	public float damage = 10;
	public LayerMask whatToHit;
	public Transform FriendlyBulletsPrefab;
	float timeToSpawnEffect = 0;
	float timeToFire = 0;
	float effectSpawnRate = 10;
	Transform firePoint;
	public bool hitEnemy = false;
	public bool hitCover = false;
	public static RaycastHit2D hit;

	public AudioClip shootSound;
	public AudioSource source;
	private float volLowRange = .5f;
	private float volHighRange = 1.0f;


	public int level = 1;
	public int killCount = 0;
	public int killLimit = 4;



	// Use this for initialization
	void Awake () 
	{
		

		firePoint = transform.FindChild ("FirePoint");
		if (firePoint == null) 
		{
			Debug.LogError ("NO FIREPOINT");
		}
	}



	
	// Update is called once per frame
	void FixedUpdate () 
	{
		if (killCount == killLimit) {
			Debug.Log ("Level Over");
			//SceneManager.LoadScene (2); LOAD NEXT LEVEL
		}
		float vol = Random.Range (volLowRange, volHighRange);
		if (fireRate == 0) 
		{
			if (Input.GetButtonDown ( "Fire1" )) 
			{
				source.Play ();
				Shoot ();

			}
		} 
		else 
		{
			if (Input.GetButtonDown ( "Fire1" ) && Time.time > timeToFire )
			{
				timeToFire = Time.time + 1 / fireRate;
				Shoot ();

			}

		}
	}


	void Shoot () 
	{
		
		Vector2 mousePosition = new Vector2 ( Camera.main.ScreenToWorldPoint ( Input.mousePosition).x , Camera.main.ScreenToWorldPoint(Input.mousePosition).y );

		Vector2 firePointPosition = new Vector2 ( firePoint.position.x, firePoint.position.y );

		hit = Physics2D.Raycast ( firePointPosition, mousePosition-firePointPosition, 100, whatToHit); 
		//third arg here is distance so we can set this in case we wanna have short distance for certain
		//weapons aka magic and shotguns and shittttttt

		//Debug.DrawLine (firePointPosition, (mousePosition-firePointPosition)*100, Color.blue);
		if (hit.collider != null) {
			hitEnemy = true;
			//Debug.DrawLine (firePointPosition, hit.point, Color.red);
			Debug.Log ("hit " + hit.collider.name + " for " + damage + " damage.");
			if (hit.collider.gameObject.tag == "Enemy") {
				//gm.enemyAmount = gm.enemyAmount - 1;
				//ps.transform.position = hit.collider.gameObject.transform.position
			
			
				Destroy (hit.collider.gameObject); //THIS IS WHERE THE ENEMY IS KILLED
				PlayerPrefs.SetInt("kills", PlayerPrefs.GetInt("kills") + 1); //THIS IS WHERE WE COUNT THE KILLS
				//hit.collider.gameObject.
			}
			if (hit.collider.gameObject.tag == "Cover") 
			{
				//Destroy (GameObject.FindWithTag("bullet"));
				Debug.Log("destroy this bullet");
			}
		
		} else {
			hitEnemy = false;
		}

		if (Time.time >= timeToSpawnEffect) 
		{
			Effect ();
			timeToSpawnEffect = Time.time + 1 / effectSpawnRate;
		}

	}


	void Effect ()
	{
		Instantiate (FriendlyBulletsPrefab, firePoint.position, firePoint.rotation);
		//Instantiate (friendlyBullet, firePoint.position, firePoint.rotation);


	}

	public bool returnHit()
	{
		return hitEnemy;
	}


}