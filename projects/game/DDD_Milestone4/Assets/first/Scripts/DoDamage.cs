using UnityEngine;
using System.Collections;

public class DoDamage : MonoBehaviour {

	void OnTriggerEnter2D (Collider2D other)
	{
		//Debug.Log ("Is in");
		if (other.gameObject.tag == "Player") {
			//Debug.Log ("PlayerHit");
			//GameObject.Find("Player").gameObject.
			//THIS DOES PLAYER DAMAGE
			PlayerPrefs.SetInt("health", PlayerPrefs.GetInt("health") - 1);
		}
	}
}

