using UnityEngine;
using System.Collections;

public class PlayerWalkAnimation : MonoBehaviour {
	Animator animator;


	void Start () 
	{
		animator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		//if (Input.GetAxisRaw ("Up") == 1.0) 
		//{
		//	animator.SetBool ("walkingUp", true);
		//} 
		if (Input.GetAxis ("Vertical") == 1.0 || Input.GetAxis("Horizontal") == 1.0) 
		{
			animator.SetBool ("isWalking", true);
		} 
		else 
		{
			animator.SetBool ("isWalking", false);
		}
	}
}
