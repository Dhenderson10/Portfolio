using UnityEngine;
using System.Collections;

public class WalkingScript : MonoBehaviour {
	Animator animator;


	void Start () 
	{
		animator = GetComponent<Animator> ();
	}

	// Update is called once per frame
	void Update () {
		//if (Input.GetAxisRaw ("Up") == 1.0) 
		//{
		//	animator.SetBool ("walkingUp", true);
		//} 
		if (Input.GetButtonDown("Vertical") == true)//|| Input.GetAxis("Horizontal") == 1.0) 
		{
			animator.SetBool ("walk", true);
		} 
		else 
		{
			animator.SetBool ("walk", false);
		}
	}
}