
<?php
	$str = file_get_contents('https://www.instagram.com/'.variable_get('username').'/?__a=1');
	$json = json_decode($str, true); 
	$count = (variable_get('count_post')) ? variable_get('count_post')-1 : 2;
?>
<div class="profile-instagram-name"><?php print_r($json['graphql']['user']['full_name']); ?> </div>
<div class="profile-instagram-msj"><?php print(t('Publicaciones Destacadas')); ?> </div>

<div class="instagram-container-post">
	<?php foreach ($json['graphql']['user']['edge_owner_to_timeline_media']['edges'] as $key => $value): ?>
		<?php if($key <= $count): ?>
		<div class="image-post-instagram">
			<?php
				  $variables = array(
				      'path' => $value['node']['display_url'], 
				      'alt' => 'Test alt',
				      'title' => 'Test title',
				      'width' => '50%',
				      'height' => '50%',
				      'attributes' => array('class' => 'img-post-instagram', 'id' => $key),
				      );
				  $img = theme('image', $variables);
			?>
			<?php print($img); ?>
		</div>
	<?php endif; ?>
	<?php endforeach; ?>
</div>